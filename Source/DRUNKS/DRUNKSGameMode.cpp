// Copyright Epic Games, Inc. All Rights Reserved.

#include "DRUNKSGameMode.h"
#include "DRUNKSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADRUNKSGameMode::ADRUNKSGameMode()
{

	// set default pawn class to BP_DRUNKSCharacter
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_DRUNKSCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default player controller to BP_DRUNKSCharacter_PC
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/BP_DRUNKSCharacter_PC"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
