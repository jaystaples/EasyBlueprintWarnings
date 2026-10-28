#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "EasyBlueprintWarningsSettings.generated.h"

/**
 * Project Settings > Plugins > Easy Blueprint Warnings
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Easy Blueprint Warnings"))
class EASYBLUEPRINTWARNINGS_API UEasyBlueprintWarningsSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UEasyBlueprintWarningsSettings()
	{
		CategoryName = TEXT("Plugins");
	}

	/** Master switch. When off, Blueprint Warning nodes do nothing at all. (Also toggle at runtime with the console: EasyBlueprintWarnings.Enabled 0/1) */
	UPROPERTY(Config, EditAnywhere, Category = "Easy Blueprint Warnings")
	bool bEnabled = true;

	/** Show the blocking Continue / Retry / Stop pop-up during Play In Editor. When off, warnings are only written to the log and the PIE Message Log. */
	UPROPERTY(Config, EditAnywhere, Category = "Easy Blueprint Warnings", meta = (EditCondition = "bEnabled"))
	bool bShowPopupInEditor = true;

	/** Pause game audio while the pop-up is open. */
	UPROPERTY(Config, EditAnywhere, Category = "Easy Blueprint Warnings", meta = (EditCondition = "bEnabled && bShowPopupInEditor"))
	bool bPauseAudioDuringPopup = true;

	/** In standalone / packaged Development builds (no editor), print the warning on screen as well as to the log. */
	UPROPERTY(Config, EditAnywhere, Category = "Easy Blueprint Warnings", meta = (EditCondition = "bEnabled"))
	bool bOnScreenMessageOutsideEditor = true;
};
