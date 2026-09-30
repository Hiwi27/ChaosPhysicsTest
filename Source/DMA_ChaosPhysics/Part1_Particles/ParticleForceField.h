// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParticleForceField.generated.h"

class ASolid;
class ARotationalParticle;
class AParticle;
class UBoxComponent;
class UArrowComponent;

UCLASS()
class DMA_CHAOSPHYSICS_API AParticleForceField : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionMeshForceField;

	UPROPERTY(EditAnywhere)
	UArrowComponent* ArrowComponent;

	UPROPERTY()
	TArray<ASolid*> SolidArray;

	UPROPERTY()
	TArray<AParticle*> ParticleArray;

	UPROPERTY()
	TArray<ARotationalParticle*> RotationParticleArray;

public:

	UPROPERTY(EditAnywhere)
	float Force;

	UPROPERTY()
	FVector ForceDirection;
	
	// Sets default values for this actor's properties
	AParticleForceField();
	
	UFUNCTION()
	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
