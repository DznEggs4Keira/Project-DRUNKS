// Copyright Epic Games, Inc. All Rights Reserved.

#include "DRUNKSGameMode.h"
#include "DRUNKSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADRUNKSGameMode::ADRUNKSGameMode()
{

	// set default pawn class to BP_PlayerCharacter
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_DRUNKSCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
