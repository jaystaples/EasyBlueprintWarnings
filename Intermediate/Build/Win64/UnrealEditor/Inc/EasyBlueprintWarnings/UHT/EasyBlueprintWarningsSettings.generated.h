// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EasyBlueprintWarningsSettings.h"

#ifdef EASYBLUEPRINTWARNINGS_EasyBlueprintWarningsSettings_generated_h
#error "EasyBlueprintWarningsSettings.generated.h already included, missing '#pragma once' in EasyBlueprintWarningsSettings.h"
#endif
#define EASYBLUEPRINTWARNINGS_EasyBlueprintWarningsSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UEasyBlueprintWarningsSettings *******************************************
struct Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics;
EASYBLUEPRINTWARNINGS_API UClass* Z_Construct_UClass_UEasyBlueprintWarningsSettings_NoRegister();

#define FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEasyBlueprintWarningsSettings(); \
	friend struct ::Z_Construct_UClass_UEasyBlueprintWarningsSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend EASYBLUEPRINTWARNINGS_API UClass* ::Z_Construct_UClass_UEasyBlueprintWarningsSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UEasyBlueprintWarningsSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/EasyBlueprintWarnings"), Z_Construct_UClass_UEasyBlueprintWarningsSettings_NoRegister) \
	DECLARE_SERIALIZER(UEasyBlueprintWarningsSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEasyBlueprintWarningsSettings(UEasyBlueprintWarningsSettings&&) = delete; \
	UEasyBlueprintWarningsSettings(const UEasyBlueprintWarningsSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEasyBlueprintWarningsSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEasyBlueprintWarningsSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEasyBlueprintWarningsSettings) \
	NO_API virtual ~UEasyBlueprintWarningsSettings();


#define FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h_10_PROLOG
#define FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h_13_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEasyBlueprintWarningsSettings;

// ********** End Class UEasyBlueprintWarningsSettings *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
