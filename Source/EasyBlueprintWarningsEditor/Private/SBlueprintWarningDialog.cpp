#include "SBlueprintWarningDialog.h"

#include "Brushes/SlateRoundedBoxBrush.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Docking/TabManager.h"
#include "GenericPlatform/ICursor.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SWindow.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "EasyBlueprintWarnings"

namespace BlueprintWarningDialog
{
	// A lovely nice happy blue.
	const FLinearColor HappyBlue        = FLinearColor::FromSRGBColor(FColor(47, 140, 255));
	const FLinearColor HappyBlueHover   = FLinearColor::FromSRGBColor(FColor(88, 166, 255));
	const FLinearColor HappyBluePressed = FLinearColor::FromSRGBColor(FColor(30, 110, 214));

	const FLinearColor Neutral        = FLinearColor::FromSRGBColor(FColor(58, 58, 62));
	const FLinearColor NeutralHover   = FLinearColor::FromSRGBColor(FColor(76, 76, 82));
	const FLinearColor NeutralPressed = FLinearColor::FromSRGBColor(FColor(44, 44, 48));

	const FLinearColor MessageBoxBg   = FLinearColor::FromSRGBColor(FColor(30, 44, 64));

	static FButtonStyle MakeButtonStyle(const FLinearColor& Normal, const FLinearColor& Hovered, const FLinearColor& Pressed)
	{
		FButtonStyle Style = FAppStyle::Get().GetWidgetStyle<FButtonStyle>("Button");
		Style.SetNormal(FSlateRoundedBoxBrush(Normal, 6.f));
		Style.SetHovered(FSlateRoundedBoxBrush(Hovered, 6.f));
		Style.SetPressed(FSlateRoundedBoxBrush(Pressed, 6.f));
		Style.SetNormalPadding(FMargin(20.f, 8.f));
		Style.SetPressedPadding(FMargin(20.f, 9.f, 20.f, 7.f));
		return Style;
	}

	static TSharedRef<SWidget> ButtonLabel(const FText& Text)
	{
		return SNew(STextBlock)
			.Text(Text)
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
			.ColorAndOpacity(FLinearColor::White)
			.Justification(ETextJustify::Center);
	}
}

void SBlueprintWarningDialog::Construct(const FArguments& InArgs)
{
	using namespace BlueprintWarningDialog;

	ParentWindow = InArgs._ParentWindow;
	ContinueStyle = MakeButtonStyle(HappyBlue, HappyBlueHover, HappyBluePressed);
	NeutralStyle  = MakeButtonStyle(Neutral, NeutralHover, NeutralPressed);

	const bool bHasDesignerMessage = !InArgs._DesignerMessage.IsEmptyOrWhitespace();
	static const FSlateRoundedBoxBrush MessageBrush(MessageBoxBg, 6.f);

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("Brushes.Panel"))
		.Padding(28.f)
		[
			SNew(SBox)
			.MinDesiredWidth(520.f)
			.MaxDesiredWidth(640.f)
			[
				SNew(SVerticalBox)

				// Error in Blueprint "BP_Name"
				+ SVerticalBox::Slot().AutoHeight().Padding(0.f, 0.f, 0.f, 16.f)
				[
					SNew(STextBlock)
					.Text(FText::Format(LOCTEXT("Heading", "Error in Blueprint \"{0}\""), InArgs._BlueprintName))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 16))
					.AutoWrapText(true)
				]

				+ SVerticalBox::Slot().AutoHeight().Padding(0.f, 0.f, 0.f, 6.f)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Hello", "Hello!"))
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 11))
				]

				+ SVerticalBox::Slot().AutoHeight().Padding(0.f, 0.f, 0.f, 14.f)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Body", "This pop-up appears when an execution path that is not supposed to happen occurs in your Blueprint."))
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 11))
					.AutoWrapText(true)
				]

				// The designer's own message from the node's Message pin
				+ SVerticalBox::Slot().AutoHeight().Padding(0.f, 0.f, 0.f, 14.f)
				[
					SNew(SBorder)
					.Visibility(bHasDesignerMessage ? EVisibility::Visible : EVisibility::Collapsed)
					.BorderImage(&MessageBrush)
					.Padding(FMargin(14.f, 10.f))
					[
						SNew(STextBlock)
						.Text(InArgs._DesignerMessage)
						.Font(FCoreStyle::GetDefaultFontStyle("Regular", 11))
						.AutoWrapText(true)
					]
				]

				// Graph / node / object
				+ SVerticalBox::Slot().AutoHeight().Padding(0.f, 0.f, 0.f, 14.f)
				[
					SNew(STextBlock)
					.Text(InArgs._Details)
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 9))
					.ColorAndOpacity(FSlateColor::UseSubduedForeground())
					.AutoWrapText(true)
				]

				+ SVerticalBox::Slot().AutoHeight().Padding(0.f, 0.f, 0.f, 22.f)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Instructions", "Press Retry to go to Blueprint, otherwise press Continue to keep playing."))
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 11))
					.AutoWrapText(true)
				]

				// Buttons
				+ SVerticalBox::Slot().AutoHeight()
				[
					SNew(SHorizontalBox)

					+ SHorizontalBox::Slot().FillWidth(1.f).VAlign(VAlign_Center)
					[
						SNew(SCheckBox)
						.IsChecked_Lambda([this]() { return bIgnoreThisNode ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
						.OnCheckStateChanged_Lambda([this](ECheckBoxState State) { bIgnoreThisNode = (State == ECheckBoxState::Checked); })
						.ToolTipText(LOCTEXT("IgnoreTip", "Handy when the warning is in Tick. Resets when Play In Editor ends."))
						[
							SNew(STextBlock)
							.Text(LOCTEXT("Ignore", "Don't show again for this node this session"))
							.Font(FCoreStyle::GetDefaultFontStyle("Regular", 9))
							.ColorAndOpacity(FSlateColor::UseSubduedForeground())
						]
					]

					+ SHorizontalBox::Slot().AutoWidth().Padding(12.f, 0.f, 0.f, 0.f)
					[
						SNew(SButton)
						.ButtonStyle(&NeutralStyle)
						.ToolTipText(LOCTEXT("StopTip", "End the Play In Editor session."))
						.OnClicked(this, &SBlueprintWarningDialog::Respond, EEasyBlueprintWarningResponse::Stop)
						[ ButtonLabel(LOCTEXT("Stop", "Stop")) ]
					]

					+ SHorizontalBox::Slot().AutoWidth().Padding(8.f, 0.f, 0.f, 0.f)
					[
						SNew(SButton)
						.ButtonStyle(&NeutralStyle)
						.ToolTipText(LOCTEXT("RetryTip", "Stop in the Blueprint debugger on this node, with the call stack."))
						.OnClicked(this, &SBlueprintWarningDialog::Respond, EEasyBlueprintWarningResponse::Retry)
						[ ButtonLabel(LOCTEXT("Retry", "Retry")) ]
					]

					+ SHorizontalBox::Slot().AutoWidth().Padding(8.f, 0.f, 0.f, 0.f)
					[
						SNew(SButton)
						.ButtonStyle(&ContinueStyle)
						.ToolTipText(LOCTEXT("ContinueTip", "Ignore it and keep playing."))
						.OnClicked(this, &SBlueprintWarningDialog::Respond, EEasyBlueprintWarningResponse::Continue)
						[ ButtonLabel(LOCTEXT("Continue", "Continue")) ]
					]
				]
			]
		]
	];
}

FReply SBlueprintWarningDialog::Respond(EEasyBlueprintWarningResponse InResponse)
{
	Response = InResponse;
	if (TSharedPtr<SWindow> Window = ParentWindow.Pin())
	{
		Window->RequestDestroyWindow();
	}
	return FReply::Handled();
}

FReply SBlueprintWarningDialog::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	const FKey Key = InKeyEvent.GetKey();
	if (Key == EKeys::Escape || Key == EKeys::Enter || Key == EKeys::SpaceBar)
	{
		return Respond(EEasyBlueprintWarningResponse::Continue);
	}
	if (Key == EKeys::R)
	{
		return Respond(EEasyBlueprintWarningResponse::Retry);
	}
	return SCompoundWidget::OnKeyDown(MyGeometry, InKeyEvent);
}

EEasyBlueprintWarningResponse SBlueprintWarningDialog::ShowModal(const FText& BlueprintName, const FText& DesignerMessage, const FText& Details, bool& bOutIgnoreThisNode)
{
	FSlateApplication& SlateApp = FSlateApplication::Get();

	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(LOCTEXT("WindowTitle", "Blueprint Warning"))
		.SizingRule(ESizingRule::Autosized)
		.AutoCenter(EAutoCenter::PreferredWorkArea)
		.SupportsMinimize(false)
		.SupportsMaximize(false)
		.FocusWhenFirstShown(true)
		.ActivationPolicy(EWindowActivationPolicy::Always);

	TSharedRef<SBlueprintWarningDialog> Dialog = SNew(SBlueprintWarningDialog)
		.ParentWindow(Window)
		.BlueprintName(BlueprintName)
		.DesignerMessage(DesignerMessage)
		.Details(Details);

	Window->SetContent(Dialog);
	Window->SetWidgetToFocusOnActivate(Dialog);

	// The PIE viewport usually has the mouse captured and hidden. Give it back.
	SlateApp.ReleaseAllPointerCapture();
	SlateApp.ResetToDefaultPointerInputSettings();
	if (TSharedPtr<ICursor> Cursor = SlateApp.GetPlatformCursor())
	{
		Cursor->Show(true);
	}

	TSharedPtr<SWindow> Parent = SlateApp.GetActiveTopLevelWindow();
	if (!Parent.IsValid())
	{
		Parent = FGlobalTabmanager::Get()->GetRootWindow();
	}

	// Runs its own Slate loop and doesn't return until the window closes: the world stops ticking meanwhile.
	SlateApp.AddModalWindow(Window, Parent);

	bOutIgnoreThisNode = Dialog->bIgnoreThisNode;
	return Dialog->Response;
}

#undef LOCTEXT_NAMESPACE
