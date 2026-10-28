#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Styling/SlateTypes.h"
#include "EasyBlueprintWarningsLibrary.h"

class SWindow;
class SButton;

/** The blocking "Error in Blueprint" pop-up. */
class SBlueprintWarningDialog : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SBlueprintWarningDialog) {}
		SLATE_ARGUMENT(TSharedPtr<SWindow>, ParentWindow)
		SLATE_ARGUMENT(FText, BlueprintName)
		SLATE_ARGUMENT(FText, DesignerMessage)
		SLATE_ARGUMENT(FText, Details)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Opens the dialog modally. Blocks the game thread (so the game is paused) until a button is pressed. */
	static EEasyBlueprintWarningResponse ShowModal(const FText& BlueprintName, const FText& DesignerMessage, const FText& Details, bool& bOutIgnoreThisNode);

	virtual bool SupportsKeyboardFocus() const override { return true; }
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;

private:
	FReply Respond(EEasyBlueprintWarningResponse InResponse);

	TWeakPtr<SWindow> ParentWindow;

	EEasyBlueprintWarningResponse Response = EEasyBlueprintWarningResponse::Continue;
	bool bIgnoreThisNode = false;

	FButtonStyle ContinueStyle;
	FButtonStyle NeutralStyle;
};
