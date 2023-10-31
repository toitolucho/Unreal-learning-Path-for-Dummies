// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cubo.generated.h"

UCLASS()
class THIRDPERSONCHARACTER_API ACubo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void moverHacia(float DeltaTime);
	void escalarHacia(float DeltaTime);
	void Rotarhacia(float DeltaTime);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY()
		USceneComponent* Root;

	UPROPERTY(EditAnyWhere)
		UStaticMeshComponent* malla;

	UPROPERTY(EditAnyWhere)
		float deltaMov;
	UPROPERTY(EditAnyWhere)
		float deltaRot;
	UPROPERTY(EditAnyWhere)
		float deltaScale;

	UPROPERTY(EditAnyWhere)
		FVector TargetPoint1;
	UPROPERTY(EditAnyWhere)
		FVector TargetPoint2;
	
	FVector CurrentTargetPoint;
	bool toTarget2 = true;

	UPROPERTY(EditAnywhere)
		TArray<UStaticMesh*> StaticMeshes;

	UPROPERTY(EditAnywhere)
		int MeshType;
	UPROPERTY(EditAnywhere)
		int ActionType;

};
