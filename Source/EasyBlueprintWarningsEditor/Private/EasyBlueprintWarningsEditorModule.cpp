#include "EasyBlueprintWarningsLibrary.h"
#include "EasyBlueprintWarningsSettings.h"
#include "SBlueprintWarningDialog.h"

#include "AudioDevice.h"
#include "Blueprint/BlueprintExceptionInfo.h"
#include "Editor.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"
#include "Engine/Blueprint.h"
#include "Engine/World.h"
#include "Framework/Application/SlateApplication.h"
#include "Kismet2/KismetDebugUtilities.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Logging/MessageLog.h"
#include "Misc/App.h"
#include "Misc/UObjectToken.h"
#include "Modules/ModuleManager.h"
#include "Subsystems/AssetEditorSubsystem.h"
#include "UObject/Script.h"
#include "UObject/Stack.h"

#define LOCTEXT_NAMESPACE "EasyBlueprintWarnings"

namespace EasyBlueprintWarnings
{
	/**
	 * Pausing the world (SetGamePaused) only silences audio from inside the audio device's per-frame Update, and that
	 * never runs while the modal pop-up is blocking the game thread. So we suspend the audio output directly instead,
	 * the same way the engine does when a mobile app goes to the background. Playback resumes exactly where it was.
	 */
	class FScopedPIEAudioPause
	{
	public:
		explicit FScopedPIEAudioPause(bool bEnable)
		{
			if (!bEnable || !GEngine)
			{
				return;
			}

			for (const FWorldContext& WorldContext : GEngine->GetWorldContexts())
			{
				UWorld* World = WorldContext.World();
				if (WorldContext.WorldType != EWorldType::PIE || !World)
				{
					continue;
				}

				FAudioDeviceHandle Device = World->GetAudioDevice();
				if (!Device.IsValid())
				{
					continue;
				}

				const Audio::FDeviceId DeviceId = Device.GetDeviceID();
				const bool bAlreadyPaused = Suspended.ContainsByPredicate([DeviceId](const FAudioDeviceHandle& Handle) { return Handle.GetDeviceID() == DeviceId; });
				if (!bAlreadyPaused)
				{
					Device->SuspendContext();
					Suspended.Add(MoveTemp(Device));
				}
			}
		}

		~FScopedPIEAudioPause()
		{
			for (FAudioDeviceHandle& Device : Suspended)
			{
				if (Device.IsValid())
				{
					Device->ResumeContext();
				}
			}
		}

	private:
		TArray<FAudioDeviceHandle> Suspended;
	};
}

class FEasyBlueprintWarningsEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
		UEasyBlueprintWarningsLibrary::GetHandler().BindRaw(this, &FEasyBlueprintWarningsEditorModule::OnWarning);
		EndPIEHandle = FEditorDelegates::EndPIE.AddRaw(this, &FEasyBlueprintWarningsEditorModule::OnEndPIE);
	}

	virtual void ShutdownModule() override
	{
		UEasyBlueprintWarningsLibrary::GetHandler().Unbind();
		FEditorDelegates::EndPIE.Remove(EndPIEHandle);
	}

private:
	void OnEndPIE(const bool /*bIsSimulating*/)
	{
		IgnoredNodes.Reset();
	}

	void OnWarning(FEasyBlueprintWarningContext& Context)
	{
		FFrame& Stack = *Context.Frame;
		UFunction* Function = Stack.Node;

		UBlueprint* Blueprint = Function ? UBlueprint::GetBlueprintFromClass(Function->GetOuterUClass()) : nullptr;
		UEdGraphNode* Node = (Function && Context.CodeOffset != INDEX_NONE)
			? FKismetDebugUtilities::FindSourceNodeForCodeLocation(Context.SelfObject, Function, Context.CodeOffset, /*bAllowImpreciseHit*/ true)
			: nullptr;

		const FText BlueprintName = FText::FromString(Blueprint ? Blueprint->GetName() : Context.BlueprintName);
		const FText GraphName = FText::FromString((Node && Node->GetGraph()) ? Node->GetGraph()->GetName() : Context.FunctionName);
		const FText NodeTitle = Node ? Node->GetNodeTitle(ENodeTitleType::ListView) : LOCTEXT("UnknownNode", "Blueprint Warning");
		const FText Details = FText::Format(LOCTEXT("Details", "Graph: {0}   ·   Node: {1}   ·   Object: {2}"),
			GraphName, NodeTitle, FText::FromString(GetNameSafe(Context.SelfObject)));

		// PIE Message Log entry with a clickable link to the node.
		{
			FMessageLog Log("PIE");
			TSharedRef<FTokenizedMessage> Msg = Log.Error();
			Msg->AddToken(FTextToken::Create(FText::Format(LOCTEXT("LogPrefix", "Blueprint Warning in {0}:"), BlueprintName)));
			if (Node)
			{
				Msg->AddToken(FUObjectToken::Create(Node, NodeTitle));
			}
			Msg->AddToken(FTextToken::Create(FText::FromString(Context.Message)));
		}

		const UEasyBlueprintWarningsSettings* Settings = GetDefault<UEasyBlueprintWarningsSettings>();
		const FString NodeKey = FString::Printf(TEXT("%s:%d"), *GetPathNameSafe(Function), Context.CodeOffset);

		const bool bCanShowPopup =
			Settings->bShowPopupInEditor &&
			GIsPlayInEditorWorld &&
			!bDialogOpen &&
			!IgnoredNodes.Contains(NodeKey) &&
			FSlateApplication::IsInitialized() &&
			!FApp::IsUnattended() &&
			!GIsAutomationTesting;

		if (!bCanShowPopup)
		{
			return;
		}

		EEasyBlueprintWarningResponse Response;
		bool bIgnoreThisNode = false;
		{
			EasyBlueprintWarnings::FScopedPIEAudioPause AudioPause(Settings->bPauseAudioDuringPopup);
			TGuardValue<bool> DialogGuard(bDialogOpen, true);
			Response = SBlueprintWarningDialog::ShowModal(BlueprintName, FText::FromString(Context.Message), Details, bIgnoreThisNode);
		}

		if (bIgnoreThisNode)
		{
			IgnoredNodes.Add(NodeKey);
		}

		// Don't let the game see the time spent in the pop-up as one enormous frame.
		FApp::SetCurrentTime(FPlatformTime::Seconds());

		switch (Response)
		{
		case EEasyBlueprintWarningResponse::Continue:
			FSlateApplication::Get().SetAllUserFocusToGameViewport();
			break;

		case EEasyBlueprintWarningResponse::Retry:
			GoToNodeAndHalt(Blueprint, Node, Context);
			break;

		case EEasyBlueprintWarningResponse::Stop:
			if (GEditor)
			{
				GEditor->RequestEndPlayMap();
			}
			break;
		}
	}

	/**
	 * Halts in the Blueprint debugger on the node, with the live call stack, watches and Step buttons, exactly the way
	 * Raise Script Error does with "Break on Exceptions" enabled: by raising a script exception from inside the node.
	 *
	 * No breakpoint is created or removed. The previous version added a temporary breakpoint and removed it after
	 * resuming; if you also removed it by hand while halted, the breakpoint list was edited twice underneath the
	 * debugger's UI, which is the most likely cause of the crash.
	 *
	 * Must be the LAST thing the handler does: once the debugger lets go, PIE may already be ending.
	 */
	static void GoToNodeAndHalt(UBlueprint* Blueprint, UEdGraphNode* Node, FEasyBlueprintWarningContext& Context)
	{
		if (!GEditor || !Blueprint)
		{
			return;
		}

		const bool bCanHalt =
			Node != nullptr &&
			Context.Frame != nullptr &&
			IsValid(Context.SelfObject) &&
			GEditor->PlayWorld != nullptr &&
			!GEditor->ShouldEndPlayMap() &&
			!FSlateApplication::Get().InKismetDebuggingMode();

		if (!bCanHalt)
		{
			// Fallback: pause the session (same as the toolbar Pause) and show the node.
			if (GEditor->PlayWorld && !GEditor->PlayWorld->bDebugPauseExecution)
			{
				GEditor->SetPIEWorldsPaused(true);
				GEditor->PlaySessionPaused();
			}
			Blueprint->SetObjectBeingDebugged(Context.SelfObject);
			if (Node)
			{
				FKismetEditorUtilities::BringKismetToFocusAttentionOnObject(Node);
			}
			else
			{
				GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(Blueprint);
			}
			return;
		}

		// The debugger only halts for the instance selected as the debug object, so select the one that hit the node.
		Blueprint->SetObjectBeingDebugged(Context.SelfObject);

		// Opens the graph on the node, fills the Call Stack panel and runs the debugger until Resume / Step / Stop.
		// (The engine logs "Unknown breakpoint hit" here because there's no breakpoint on the node. That's expected.)
		FBlueprintCoreDelegates::ThrowScriptException(Context.SelfObject, *Context.Frame,
			FBlueprintExceptionInfo(EBlueprintExceptionType::Breakpoint,
				FText::Format(LOCTEXT("HaltDescription", "Blueprint Warning: {0}"), FText::FromString(Context.Message))));

		// Deliberately nothing after this. Don't touch Node, Blueprint or the world: PIE may have been stopped.
	}

	TSet<FString> IgnoredNodes;
	FDelegateHandle EndPIEHandle;
	bool bDialogOpen = false;
};

IMPLEMENT_MODULE(FEasyBlueprintWarningsEditorModule, EasyBlueprintWarningsEditor)

#undef LOCTEXT_NAMESPACE
