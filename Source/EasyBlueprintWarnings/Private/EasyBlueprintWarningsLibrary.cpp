#include "EasyBlueprintWarningsLibrary.h"
#include "EasyBlueprintWarningsSettings.h"
#include "Engine/Engine.h"
#include "HAL/IConsoleManager.h"
#include "UObject/Stack.h"

DEFINE_LOG_CATEGORY_STATIC(LogEasyBlueprintWarnings, Log, All);

static TAutoConsoleVariable<bool> CVarEasyBlueprintWarningsEnabled(
	TEXT("EasyBlueprintWarnings.Enabled"),
	true,
	TEXT("Runtime toggle for Blueprint Warning nodes (the project setting must also be enabled)."));

FEasyBlueprintWarningHandler& UEasyBlueprintWarningsLibrary::GetHandler()
{
	static FEasyBlueprintWarningHandler Handler;
	return Handler;
}

void UEasyBlueprintWarningsLibrary::BlueprintWarning(const FString& Message)
{
	// Only reached when called directly from C++, where there is no Blueprint frame to point at.
	UE_LOG(LogEasyBlueprintWarnings, Error, TEXT("Blueprint Warning (C++): %s"), *Message);
}

DEFINE_FUNCTION(UEasyBlueprintWarningsLibrary::execBlueprintWarning)
{
	// Custom thunk so we get the *calling Blueprint's* frame: its object, function and bytecode position.
	P_GET_PROPERTY(FStrProperty, Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	HandleWarning(Stack, Z_Param_Message);
	P_NATIVE_END;
}

void UEasyBlueprintWarningsLibrary::HandleWarning(FFrame& Stack, const FString& Message)
{
#if !UE_BUILD_SHIPPING
	const UEasyBlueprintWarningsSettings* Settings = GetDefault<UEasyBlueprintWarningsSettings>();
	if (!Settings->bEnabled || !CVarEasyBlueprintWarningsEnabled.GetValueOnGameThread())
	{
		return;
	}

	FEasyBlueprintWarningContext Context;
	Context.Frame = &Stack;
	Context.SelfObject = Stack.Object;
	Context.Message = Message;

	if (UFunction* Function = Stack.Node)
	{
		Context.FunctionName = Function->GetName();

		if (const UClass* OwnerClass = Function->GetOuterUClass())
		{
			Context.BlueprintName = OwnerClass->GetName();
			Context.BlueprintName.RemoveFromEnd(TEXT("_C"));
		}

		if (Stack.Code && Function->Script.Num() > 0)
		{
			// Same convention the Kismet debugger uses to map a frame back to a graph node.
			Context.CodeOffset = UE_PTRDIFF_TO_INT32(Stack.Code - Function->Script.GetData()) - 1;
		}
	}

	UE_LOG(LogEasyBlueprintWarnings, Error, TEXT("Blueprint Warning hit in '%s' (%s, self: %s): %s"),
		*Context.BlueprintName, *Context.FunctionName, *GetNameSafe(Context.SelfObject), *Message);

	if (GetHandler().IsBound())
	{
		GetHandler().Execute(Context);
		return;
	}

	// No editor: standalone or packaged Development build.
	if (Settings->bOnScreenMessageOutsideEditor && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor(47, 140, 255),
			FString::Printf(TEXT("Blueprint Warning in \"%s\": %s"), *Context.BlueprintName, *Message));
	}
#endif
}
