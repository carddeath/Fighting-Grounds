// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "S05_Fighting_Grounds.h"
#include "S05_Fighting_GroundsGameMode.h"
#include "S05_Fighting_GroundsHUD.h"
#include "Player/FirstPersonCharacter.h"

AS05_Fighting_GroundsGameMode::AS05_Fighting_GroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_Fighting_GroundsHUD::StaticClass();
}
