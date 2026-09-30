// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particle.generated.h"

UCLASS()
class DMA_CHAOSPHYSICS_API AParticle : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	float TimeAlive;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY()
	USceneComponent* SceneComponent;

public:
	UPROPERTY(EditAnywhere)
	FVector Position;
	
	UPROPERTY(EditAnywhere)
	FVector Velocity;
	
	UPROPERTY(EditAnywhere)
	FVector Acceleration;

	UPROPERTY(EditAnywhere)
	float Mass;

	UPROPERTY(EditAnywhere)
	float Inertia;
	
	UPROPERTY(EditAnywhere)
	float LifeSpan;

	// Sets default values for this actor's properties
	AParticle();

	void Initialize(FVector _Velocity, FVector _Acceleration);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
