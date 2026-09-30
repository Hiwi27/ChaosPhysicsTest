// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyParticleEmitter.h"
#include "RotationalParticleEmitter.generated.h"

class ARotationalParticle;

UCLASS()
class DMA_CHAOSPHYSICS_API ARotationalParticleEmitter : public AMyParticleEmitter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<ARotationalParticle*> myRotationalParticles;

	UPROPERTY(EditAnywhere)
	float MinAngularVelocity;

	UPROPERTY(EditAnywhere)
	float MaxAngularVelocity;

	UPROPERTY(EditAnywhere)
	float MinAngularAcceleration;

	UPROPERTY(EditAnywhere)
	float MaxAngularAcceleration;

	
	// Sets default values for this actor's properties
	ARotationalParticleEmitter();

	virtual void SpawnParticles(float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
