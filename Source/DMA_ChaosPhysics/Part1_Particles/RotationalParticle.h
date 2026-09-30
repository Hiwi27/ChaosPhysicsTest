// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particle.h"
#include "RotationalParticle.generated.h"

UCLASS()
class DMA_CHAOSPHYSICS_API ARotationalParticle : public AParticle
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	FRotator Rotation;

	UPROPERTY()
	FRotator AngularVelocity;

	UPROPERTY()
	FRotator AngularAcceleration;
	// Sets default values for this actor's properties
	ARotationalParticle();

	void InitializeRotation(FRotator _AngularVelocity, FRotator _AngularAcceleration);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
