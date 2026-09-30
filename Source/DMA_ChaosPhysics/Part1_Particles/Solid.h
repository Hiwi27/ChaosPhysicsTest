// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Solid.generated.h"

UCLASS()
class DMA_CHAOSPHYSICS_API ASolid : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Attributes")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY()
	USceneComponent* SceneComponent;

public:
	bool Colliding;

	UPROPERTY(EditAnywhere)
	FVector Position;
	
	UPROPERTY(EditAnywhere)
	FVector Velocity;
	
	UPROPERTY(EditAnywhere)
	FVector Acceleration;

	UPROPERTY(EditAnywhere)
	float Radius;

	UPROPERTY(EditAnywhere)
	float Mass;

	UPROPERTY(EditAnywhere)
	float Inertia;

public:
	// Sets default values for this actor's properties
	ASolid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
