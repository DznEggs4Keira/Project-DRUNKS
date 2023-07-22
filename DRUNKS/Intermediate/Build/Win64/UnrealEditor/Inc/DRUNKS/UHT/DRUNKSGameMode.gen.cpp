// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DRUNKS/DRUNKSGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDRUNKSGameMode() {}
// Cross Module References
	DRUNKS_API UClass* Z_Construct_UClass_ADRUNKSGameMode();
	DRUNKS_API UClass* Z_Construct_UClass_ADRUNKSGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_DRUNKS();
// End Cross Module References
	void ADRUNKSGameMode::StaticRegisterNativesADRUNKSGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADRUNKSGameMode);
	UClass* Z_Construct_UClass_ADRUNKSGameMode_NoRegister()
	{
		return ADRUNKSGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ADRUNKSGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADRUNKSGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_DRUNKS,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADRUNKSGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "DRUNKSGameMode.h" },
		{ "ModuleRelativePath", "DRUNKSGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADRUNKSGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADRUNKSGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADRUNKSGameMode_Statics::ClassParams = {
		&ADRUNKSGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ADRUNKSGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADRUNKSGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADRUNKSGameMode()
	{
		if (!Z_Registration_Info_UClass_ADRUNKSGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADRUNKSGameMode.OuterSingleton, Z_Construct_UClass_ADRUNKSGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADRUNKSGameMode.OuterSingleton;
	}
	template<> DRUNKS_API UClass* StaticClass<ADRUNKSGameMode>()
	{
		return ADRUNKSGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADRUNKSGameMode);
	ADRUNKSGameMode::~ADRUNKSGameMode() {}
	struct Z_CompiledInDeferFile_FID_Work_Projects_Project_DRUNKS_DRUNKS_Source_DRUNKS_DRUNKSGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Projects_Project_DRUNKS_DRUNKS_Source_DRUNKS_DRUNKSGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADRUNKSGameMode, ADRUNKSGameMode::StaticClass, TEXT("ADRUNKSGameMode"), &Z_Registration_Info_UClass_ADRUNKSGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADRUNKSGameMode), 2696102865U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Projects_Project_DRUNKS_DRUNKS_Source_DRUNKS_DRUNKSGameMode_h_479757300(TEXT("/Script/DRUNKS"),
		Z_CompiledInDeferFile_FID_Work_Projects_Project_DRUNKS_DRUNKS_Source_DRUNKS_DRUNKSGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Projects_Project_DRUNKS_DRUNKS_Source_DRUNKS_DRUNKSGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
