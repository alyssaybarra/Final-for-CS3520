// Copyright Epic Games, Inc. All Rights Reserved.

#include "CS3520FinalGameMode.h"
#include "CS3520FinalCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACS3520FinalGameMode::ACS3520FinalGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
