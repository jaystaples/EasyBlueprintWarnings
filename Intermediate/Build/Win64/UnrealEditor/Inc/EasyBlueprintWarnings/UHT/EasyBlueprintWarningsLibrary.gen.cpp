// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyBlueprintWarningsLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeEasyBlueprintWarningsLibrary() {}

// ********** Begin Cross Module References ********************************************************
EASYBLUEPRINTWARNINGS_API UClass* Z_Construct_UClass_UEasyBlueprintWarningsLibrary();
EASYBLUEPRINTWARNINGS_API UClass* Z_Construct_UClass_UEasyBlueprintWarningsLibrary_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UPackage* Z_Construct_UPackage__Script_EasyBlueprintWarnings();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEasyBlueprintWarningsLibrary Function BlueprintWarning ******************
struct Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics
{
	struct EasyBlueprintWarningsLibrary_eventBlueprintWarning_Parms
	{
		FString Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Development" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Place this on an execution path that should never happen.\n\x09 * In Play In Editor it pauses the game with a pop-up: Continue keeps playing, Retry jumps to this node in the\n\x09 * Blueprint debugger, Stop ends the session. Stripped from Shipping builds.\n\x09 *\n\x09 * @param Message\x09""Extra context shown in the pop-up and the log.\n\x09 */" },
#endif
		{ "CPP_Default_Message", "Something went wrong" },
		{ "CustomThunk", "true" },
		{ "DevelopmentOnly", "" },
		{ "DisplayName", "Blueprint Warning" },
		{ "Keywords", "assert error raise script check ensure never warning" },
		{ "ModuleRelativePath", "Public/EasyBlueprintWarningsLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Place this on an execution path that should never happen.\nIn Play In Editor it pauses the game with a pop-up: Continue keeps playing, Retry jumps to this node in the\nBlueprint debugger, Stop ends the session. Stripped from Shipping builds.\n\n@param Message       Extra context shown in the pop-up and the log." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BlueprintWarning constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BlueprintWarning constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BlueprintWarning Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyBlueprintWarningsLibrary_eventBlueprintWarning_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::PropPointers) < 2048);
// ********** End Function BlueprintWarning Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEasyBlueprintWarningsLibrary, nullptr, "BlueprintWarning", 	Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::EasyBlueprintWarningsLibrary_eventBlueprintWarning_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::EasyBlueprintWarningsLibrary_eventBlueprintWarning_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEasyBlueprintWarningsLibrary Function BlueprintWarning ********************

// ********** Begin Class UEasyBlueprintWarningsLibrary ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UEasyBlueprintWarningsLibrary;
UClass* UEasyBlueprintWarningsLibrary::GetPrivateStaticClass()
{
	using TClass = UEasyBlueprintWarningsLibrary;
	if (!Z_Registration_Info_UClass_UEasyBlueprintWarningsLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("EasyBlueprintWarningsLibrary"),
			Z_Registration_Info_UClass_UEasyBlueprintWarningsLibrary.InnerSingleton,
			StaticRegisterNativesUEasyBlueprintWarningsLibrary,
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
	return Z_Registration_Info_UClass_UEasyBlueprintWarningsLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UEasyBlueprintWarningsLibrary_NoRegister()
{
	return UEasyBlueprintWarningsLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEasyBlueprintWarningsLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "EasyBlueprintWarningsLibrary.h" },
		{ "ModuleRelativePath", "Public/EasyBlueprintWarningsLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UEasyBlueprintWarningsLibrary constinit property declarations ************
// ********** End Class UEasyBlueprintWarningsLibrary constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BlueprintWarning"), .Pointer = &UEasyBlueprintWarningsLibrary::execBlueprintWarning },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEasyBlueprintWarningsLibrary_BlueprintWarning, "BlueprintWarning" }, // 2457671324
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEasyBlueprintWarningsLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UEasyBlueprintWarningsLibrary_Statics
UObject* (*const Z_Construct_UClass_UEasyBlueprintWarningsLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_EasyBlueprintWarnings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyBlueprintWarningsLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEasyBlueprintWarningsLibrary_Statics::ClassParams = {
	&UEasyBlueprintWarningsLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyBlueprintWarningsLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UEasyBlueprintWarningsLibrary_Statics::Class_MetaDataParams)
};
void UEasyBlueprintWarningsLibrary::StaticRegisterNativesUEasyBlueprintWarningsLibrary()
{
	UClass* Class = UEasyBlueprintWarningsLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UEasyBlueprintWarningsLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UEasyBlueprintWarningsLibrary()
{
	if (!Z_Registration_Info_UClass_UEasyBlueprintWarningsLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEasyBlueprintWarningsLibrary.OuterSingleton, Z_Construct_UClass_UEasyBlueprintWarningsLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEasyBlueprintWarningsLibrary.OuterSingleton;
}
UEasyBlueprintWarningsLibrary::UEasyBlueprintWarningsLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UEasyBlueprintWarningsLibrary);
UEasyBlueprintWarningsLibrary::~UEasyBlueprintWarningsLibrary() {}
// ********** End Class UEasyBlueprintWarningsLibrary **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsLibrary_h__Script_EasyBlueprintWarnings_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEasyBlueprintWarningsLibrary, UEasyBlueprintWarningsLibrary::StaticClass, TEXT("UEasyBlueprintWarningsLibrary"), &Z_Registration_Info_UClass_UEasyBlueprintWarningsLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEasyBlueprintWarningsLibrary), 2395083723U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsLibrary_h__Script_EasyBlueprintWarnings_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsLibrary_h__Script_EasyBlueprintWarnings_2358521131{
	TEXT("/Script/EasyBlueprintWarnings"),
	Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsLibrary_h__Script_EasyBlueprintWarnings_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Plugins_EasyBlueprintWarnings_Source_EasyBlueprintWarnings_Public_EasyBlueprintWarningsLibrary_h__Script_EasyBlueprintWarnings_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
