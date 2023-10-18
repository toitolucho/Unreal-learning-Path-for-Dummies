// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubo.h"

// Sets default values
ACubo::ACubo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Parent"));
	RootComponent = Root;

	malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	malla->AttachTo(Root);


	deltaMov = 0.5;
	deltaScale = 1.005;
	deltaRot = 1;
}

// Called when the game starts or when spawned
void ACubo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector previuScale = this->GetActorRelativeScale3D();  // malla->GetRelativeScale3D();
	//this->SetActorRelativeScale3D(previuScale * deltaScale);

	//SetActorLocation(FVector(1, 1, 1));
	FVector previusLocation = GetActorLocation();
	previusLocation.Y += deltaMov;
	//previusLocation.Y = previusLocation.Y + 0.1;
	SetActorLocation(previusLocation);

}

