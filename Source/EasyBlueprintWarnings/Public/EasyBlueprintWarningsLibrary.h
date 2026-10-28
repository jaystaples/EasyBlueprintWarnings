#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EasyBlueprintWarningsLibrary.generated.h"

/** What the person chose in the pop-up. */
enum class EEasyBlueprintWarningResponse : uint8
{
	Continue,
	Retry,
	Stop
};

/** Everything the editor needs to describe and locate the node that fired. */
struct FEasyBlueprintWarningContext
{
	/** The Blueprint frame that executed the Blueprint Warning node. Only valid for the duration of the handler. */
	FFrame* Frame = nullptr;

	/** "Self" of the Blueprint that hit the node. */
	UObject* SelfObject = nullptr;

	FString Message;
	FString BlueprintName;
	FString FunctionName;

	/** Bytecode offset inside Frame->Node, used to find the exact graph node. */
	int32 CodeOffset = INDEX_NONE;
};

DECLARE_DELEGATE_OneParam(FEasyBlueprintWarningHandler, FEasyBlueprintWarningContext& /*Context*/);

UCLASS()
class EASYBLUEPRINTWARNINGS_API UEasyBlueprintWarningsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Place this on an execution path that should never happen.
	 * In Play In Editor it pauses the game with a pop-up: Continue keeps playing, Retry jumps to this node in the
	 * Blueprint debugger, Stop ends the session. Stripped from Shipping builds.
	 *
	 * @param Message	Extra context shown in the pop-up and the log.
	 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category = "Development",
		meta = (DevelopmentOnly, DisplayName = "Blueprint Warning", Keywords = "assert error raise script check ensure never warning"))
	static void BlueprintWarning(const FString& Message = FString(TEXT("This should never happen")));
	DECLARE_FUNCTION(execBlueprintWarning);

	/** The editor module binds this to show the pop-up. Unbound in standalone / packaged builds. */
	static FEasyBlueprintWarningHandler& GetHandler();

private:
	static void HandleWarning(FFrame& Stack, const FString& Message);
};
