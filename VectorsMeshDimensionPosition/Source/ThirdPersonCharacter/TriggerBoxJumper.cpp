// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerBoxJumper.h"


ATriggerBoxJumper::ATriggerBoxJumper()
{
	OnActorBeginOverlap.AddDynamic(this, &ATriggerBoxJumper::colisionar);
}

void ATriggerBoxJumper::BeginPlay()
{
	Super::BeginPlay();
}
void ATriggerBoxJumper::colisionar(class AActor* cajaFantasma, class AActor* nave)
{
	//muestra un mensaje en la pantalla
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("me colisionaron"));
	if (player)
	{
		player->levantarBloques();
	}
	
}