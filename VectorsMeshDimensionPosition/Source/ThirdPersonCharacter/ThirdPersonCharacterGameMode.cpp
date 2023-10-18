// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonCharacterGameMode.h"
#include "ThirdPersonCharacterPlayerController.h"
#include "ThirdPersonCharacterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThirdPersonCharacterGameMode::AThirdPersonCharacterGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AThirdPersonCharacterPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}