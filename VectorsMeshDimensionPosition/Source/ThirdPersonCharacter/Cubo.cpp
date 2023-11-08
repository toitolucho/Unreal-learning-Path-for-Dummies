// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubo.h"
#include <GameFramework/CharacterMovementComponent.h>
#include <Animation/AnimNode_Inertialization.h>
#include "ThirdPersonCharacterGameMode.h"

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
	enabled = false;
	
}

// Called when the game starts or when spawned
void ACubo::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogActor, Warning, TEXT("Initial Rotation of Actor %s"), *this->GetActorRotation().ToString());
	UE_LOG(LogActor, Warning, TEXT("Initial Scale %s"), *this->GetActorRelativeScale3D().ToString());
	SetActorRotation(FRotator(0, 45, 0));
	if(ActionType==1)
		SetActorLocation(TargetPoint1);
	if (ActionType == 2)
		SetActorScale3D(TargetPoint1);
	if (ActionType == 3)
		SetActorRotation(FRotator(TargetPoint1.X, TargetPoint1.Y, TargetPoint1.Z));
	CurrentTargetPoint = TargetPoint2;
	UE_LOG(LogActor, Warning, TEXT("Updated Rotation of Actor %s"), *this->GetActorRotation().ToString());
	UE_LOG(LogActor, Warning, TEXT("After Scale %s"), *this->GetActorRelativeScale3D().ToString());

	AThirdPersonCharacterGameMode* GameMode = (AThirdPersonCharacterGameMode*)GetWorld()->GetAuthGameMode();
	UClass* DefaultPawnClass = GameMode->DefaultPawnClass;
	//DefaultPawnClass->
	//GameMode->GetDefaultPawnClassForController();
	// 
	// 
	// 
	//FRotator CurrentRotation = GetActorRotation();
	//CurrentRotation.Pitch, CurrentRotation.Yaw + deltaRot, CurrentRotation.Roll	

	//UStaticMesh* meshToUse = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus")));
	//if (meshToUse)
	//	malla->SetStaticMesh(meshToUse);


	if (this->StaticMeshes.Num() > 0)
	{
		UStaticMesh* meshToUse = nullptr;
		switch (MeshType)
		{
			case 1:
				meshToUse = StaticMeshes[0];
				break;
			case 2:
				meshToUse = StaticMeshes[1];
				break;
			case 3:
				meshToUse = StaticMeshes[2];
				break;
		default:
			break;
		}
		if (meshToUse)
		{
			malla->SetStaticMesh(meshToUse);
		}
	}
		
}

void ACubo::moverHacia(float DeltaTime)
{
	// Set the speed at which the actor should move
	float speed = deltaMov;

	// Set the target location
	FVector targetLocation = CurrentTargetPoint;

	// Get the current location of the actor
	FVector currentLocation = GetActorLocation();

	// Calculate the new location of the actor based on the speed and target location
	FVector newLocation = FMath::VInterpTo(currentLocation, targetLocation, DeltaTime, speed);

	// Set the new location of the actor
	SetActorLocation(newLocation);
	if ((newLocation - targetLocation).Size() < 10.0f)
	{
		// Calculate the new location of the actor based on the speed and second target location
		//newLocation = FMath::VInterpTo(newLocation, targetLocation2, 0.01f, speed);
		CurrentTargetPoint = toTarget2 ? TargetPoint1:TargetPoint2;
		toTarget2 = !toTarget2;
	}
}

void ACubo::escalarHacia(float DeltaTime)
{
	//FVector previuScale = this->GetActorRelativeScale3D();  // malla->GetRelativeScale3D();
	//this->SetActorRelativeScale3D(previuScale * deltaScale);


	FVector targetScale = CurrentTargetPoint;

	// Get the current location of the actor
	FVector currentScale = this->GetActorScale();

	// Calculate the new location of the actor based on the speed and target location
	FVector newScale = FMath::VInterpTo(currentScale, targetScale, DeltaTime, deltaScale);
	//FVector newScale = currentScale * deltaScale;
	//UE_LOG(LogActor, Warning, TEXT("New Scale %s"), *newScale.ToString());
	// Set the new location of the actor
	this->SetActorScale3D(newScale);
	if ((newScale - targetScale).Size() < 0.5f)
	{
		// Calculate the new location of the actor based on the speed and second target location
		//newLocation = FMath::VInterpTo(newLocation, targetLocation2, 0.01f, speed);
		CurrentTargetPoint = toTarget2 ? TargetPoint1 : TargetPoint2;
		toTarget2 = !toTarget2;
	}
}

void ACubo::Rotarhacia(float DeltaTime)
{
	/*FRotator CurrentRotation = GetActorRotation();
	FRotator NewRotation = FRotator(CurrentRotation.Pitch, CurrentRotation.Yaw + deltaRot, CurrentRotation.Roll );
	SetActorRotation(NewRotation);*/


	FRotator targetAngule = FRotator(CurrentTargetPoint.X, CurrentTargetPoint.Y, CurrentTargetPoint.Z);

	// Get the current location of the actor
	FRotator currentAngule = this->GetActorRotation();

	// Calculate the new location of the actor based on the speed and target location
	FRotator newAngule = FMath::RInterpTo(currentAngule, targetAngule, DeltaTime, deltaScale);
	
	//FVector newScale = currentScale * deltaScale;
	//UE_LOG(LogActor, Warning, TEXT("New Scale %s"), *newScale.ToString());
	// Set the new location of the actor
	this->SetActorRotation(newAngule);
	if ((newAngule - targetAngule).IsNearlyZero(0.05) )
	{
		// Calculate the new location of the actor based on the speed and second target location
		//newLocation = FMath::VInterpTo(newLocation, targetLocation2, 0.01f, speed);
		CurrentTargetPoint = toTarget2 ? TargetPoint1 : TargetPoint2;
		toTarget2 = !toTarget2;
	}
}



// Called every frame
void ACubo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	

	//SetActorLocation(FVector(1, 1, 1));
	//FVector previusLocation = GetActorLocation();

	/*+180
	-300*/

	//if (previusLocation.Y >= 180)
	//	deltaMov *= -1;
	//if (previusLocation.Y <= -300)
	//	deltaMov *= -1;
	//previusLocation.Y += deltaMov;
	////previusLocation.Y = previusLocation.Y + 0.1;
	//SetActorLocation(previusLocation);

	if (enabled)
	{
		if (ActionType == 1)
			moverHacia(DeltaTime);
		else if (ActionType == 2)
			escalarHacia(DeltaTime);
		else if (ActionType == 3)
			Rotarhacia(DeltaTime);
	}
	
	
}

void ACubo::iniciarMovimiento()
{
	enabled = true;
}

