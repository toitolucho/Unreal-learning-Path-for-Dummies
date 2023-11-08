// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ThirdPersonCharacterCharacter.h"
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TriggerBoxJumper.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONCHARACTER_API ATriggerBoxJumper : public ATriggerBox
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnyWhere)
		AThirdPersonCharacterCharacter* player;

	ATriggerBoxJumper();

	virtual void BeginPlay();
	UFUNCTION()
		void colisionar(class AActor* cajaFantasma, class AActor* nave);
	
};
