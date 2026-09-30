// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyParticleEmitter.generated.h"

class AParticle;

UCLASS()
class DMA_CHAOSPHYSICS_API AMyParticleEmitter : public AActor
{
	GENERATED_BODY()


	
public:
	UPROPERTY()
	TArray<AParticle*> myParticles;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AParticle> ParticlesToSpawn;

	UPROPERTY(EditAnywhere)
	float EmissionTimeStep;

	UPROPERTY(EditAnywhere)
	float MinVelocity;

	UPROPERTY(EditAnywhere)
	float MaxVelocity;

	UPROPERTY(EditAnywhere)
	float MinAcceleration;

	UPROPERTY(EditAnywhere)
	float MaxAcceleration;

protected:
	float LastEmision;

public:
	// Sets default values for this actor's properties
	AMyParticleEmitter();

	virtual void SpawnParticles(float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
