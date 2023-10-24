// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeActor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ThirdPersonCharacterCharacter.h"

// Sets default values
ACubeActor::ACubeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Controlador"));
	RootComponent = Root;

	malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla_Mesh"));
	malla->AttachTo(Root);

}

// Called when the game starts or when spawned
void ACubeActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogActor, Warning, TEXT("Hello world from %s"), *this->GetName());
	//UE_LOG(LogActor, Warning, TEXT("Position actor %d %d %d"), this->GetActorLocation().X, this->GetActorLocation().Y, this->GetActorLocation().Z);
	UE_LOG(LogActor, Warning, TEXT("Position of Actor %s"), *this->GetActorLocation().ToString() );

	currentLocation = malla->GetRelativeLocation();
	//currentLocation = malla->GetRelativeTransform()->GetLocation();

	 //UGameplayStatics::GetActorOfClass((), AThirdPersonCharacterCharacter::StaticClass());
}

// Called every frame
void ACubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector previuScale = this->GetActorRelativeScale3D();  // malla->GetRelativeScale3D();
	this->SetActorRelativeScale3D (previuScale*1.0005f);
	//this->SetActorRelativeRotation(FVector(1, 2, 3));

	float distance = this->GetDistanceTo(player);
	FVector newLocation = currentLocation;
	if (distance < 50)
		newLocation.Z += 80;
	malla->SetRelativeLocation(newLocation);
}

