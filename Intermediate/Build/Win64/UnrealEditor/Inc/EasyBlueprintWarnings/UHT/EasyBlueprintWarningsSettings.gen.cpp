// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyBlueprintWarningsSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeEasyBlueprintWarningsSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
EASYBLUEPRINTWARNINGS_API UClass* Z_Construct_UClass_UEasyBlueprintWarningsSettings();
EASYBLUEPRINTWARNINGS_API UClass* Z_Construct_UClass_UEasyBlueprintWarningsSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_EasyBlueprintWarnings();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEasyBlueprintWarningsSettings *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UEasyBlueprintWarningsSettings;
UClass* UEasyBlueprintWarningsSettings::GetPrivateStaticClass()
{
	using TClass = UEasyBlueprintWarningsSettings;
	if (!Z_Registration_Info_UClass_UEasyBlueprintWarningsSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("EasyBlueprintWarningsSettings"),
			Z_Registration_Info_UClass_UEasyBlueprintWarningsSettings.InnerSingleton,
			StaticRegisterNativesUEasyBlueprintWarningsSettings,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UEasyBlueprintWarningsSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UEasyBlueprintWarningsSettings_NoRegister()
{
	return UEasyBlueprintWarningsSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Project Settings > Plugins > Easy Blueprint Warnings\n */" },
#endif
		{ "DisplayName", "Easy Blueprint Warnings" },
		{ "IncludePath", "EasyBlueprintWarningsSettings.h" },
		{ "ModuleRelativePath", "Public/EasyBlueprintWarningsSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Project Settings > Plugins > Easy Blueprint Warnings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Easy Blueprint Warnings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch. When off, Blueprint Warning nodes do nothing at all. (Also toggle at runtime with the console: EasyBlueprintWarnings.Enabled 0/1) */" },
#endif
		{ "ModuleRelativePath", "Public/EasyBlueprintWarningsSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch. When off, Blueprint Warning nodes do nothing at all. (Also toggle at runtime with the console: EasyBlueprintWarnings.Enabled 0/1)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowPopupInEditor_MetaData[] = {
		{ "Category", "Easy Blueprint Warnings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Show the blocking Continue / Retry / Stop pop-up during Play In Editor. When off, warnings are only written to the log and the PIE Message Log. */" },
#endif
		{ "EditCondition", "bEnabled" },
		{ "ModuleRelativePath", "Public/EasyBlueprintWarningsSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show the blocking Continue / Retry / Stop pop-up during Play In Editor. When off, warnings are only written to the log and the PIE Message Log." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPauseAudioDuringPopup_MetaData[] = {
		{ "Category", "Easy Blueprint Warnings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pause game audio while the pop-up is open. */" },
#endif
		{ "EditCondition", "bEnabled && bShowPopupInEditor" },
		{ "ModuleRelativePath", "Public/EasyBlueprintWarningsSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pause game audio while the pop-up is open." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOnScreenMessageOutsideEditor_MetaData[] = {
		{ "Category", "Easy Blueprint Warnings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** In standalone / packaged Development builds (no editor), print the warning on screen as well as to the log. */" },
#endif
		{ "EditCondition", "bEnabled" },
		{ "ModuleRelativePath", "Public/EasyBlueprintWarningsSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "In standalone / packaged Development builds (no editor), print the warning on screen as well as to the log." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UEasyBlueprintWarningsSettings constinit property declarations ***********
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static void NewProp_bShowPopupInEditor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowPopupInEditor;
	static void NewProp_bPauseAudioDuringPopup_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPauseAudioDuringPopup;
	static void NewProp_bOnScreenMessageOutsideEditor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOnScreenMessageOutsideEditor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UEasyBlueprintWarningsSettings constinit property declarations *************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEasyBlueprintWarningsSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics

// ********** Begin Class UEasyBlueprintWarningsSettings Property Definitions **********************
void Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((UEasyBlueprintWarningsSettings*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEasyBlueprintWarningsSettings), &Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
void Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bShowPopupInEditor_SetBit(void* Obj)
{
	((UEasyBlueprintWarningsSettings*)Obj)->bShowPopupInEditor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bShowPopupInEditor = { "bShowPopupInEditor", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEasyBlueprintWarningsSettings), &Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bShowPopupInEditor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowPopupInEditor_MetaData), NewProp_bShowPopupInEditor_MetaData) };
void Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bPauseAudioDuringPopup_SetBit(void* Obj)
{
	((UEasyBlueprintWarningsSettings*)Obj)->bPauseAudioDuringPopup = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bPauseAudioDuringPopup = { "bPauseAudioDuringPopup", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEasyBlueprintWarningsSettings), &Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bPauseAudioDuringPopup_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPauseAudioDuringPopup_MetaData), NewProp_bPauseAudioDuringPopup_MetaData) };
void Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bOnScreenMessageOutsideEditor_SetBit(void* Obj)
{
	((UEasyBlueprintWarningsSettings*)Obj)->bOnScreenMessageOutsideEditor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bOnScreenMessageOutsideEditor = { "bOnScreenMessageOutsideEditor", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEasyBlueprintWarningsSettings), &Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bOnScreenMessageOutsideEditor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOnScreenMessageOutsideEditor_MetaData), NewProp_bOnScreenMessageOutsideEditor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bShowPopupInEditor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bPauseAudioDuringPopup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::NewProp_bOnScreenMessageOutsideEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::PropPointers) < 2048);
// ********** End Class UEasyBlueprintWarningsSettings Property Definitions ************************
UObject* (*const Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_EasyBlueprintWarnings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::ClassParams = {
	&UEasyBlueprintWarningsSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::Class_MetaDataParams)
};
void UEasyBlueprintWarningsSettings::StaticRegisterNativesUEasyBlueprintWarningsSettings()
{
}
UClass* Z_Construct_UClass_UEasyBlueprintWarningsSettings()
{
	if (!Z_Registration_Info_UClass_UEasyBlueprintWarningsSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEasyBlueprintWarningsSettings.OuterSingleton, Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEasyBlueprintWarningsSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UEasyBlueprintWarningsSettings);
UEasyBlueprintWarningsSettings::~UEasyBlueprintWarningsSettings() {}
// ********** End Class UEasyBlueprintWarningsSettings *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h__Script_EasyBlueprintWarnings_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEasyBlueprintWarningsSettings, UEasyBlueprintWarningsSettings::StaticClass, TEXT("UEasyBlueprintWarningsSettings"), &Z_Registration_Info_UClass_UEasyBlueprintWarningsSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEasyBlueprintWarningsSettings), 284860605U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h__Script_EasyBlueprintWarnings_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h__Script_EasyBlueprintWarnings_1965011636{
	TEXT("/Script/EasyBlueprintWarnings"),
	Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h__Script_EasyBlueprintWarnings_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h__Script_EasyBlueprintWarnings_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
