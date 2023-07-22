// Copyright Epic Games, Inc. All Rights Reserved.

#include "DRUNKSGameMode.h"
#include "DRUNKSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADRUNKSGameMode::ADRUNKSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
