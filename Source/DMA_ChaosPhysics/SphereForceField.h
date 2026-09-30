// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "SphereForceField.generated.h"

UCLASS()
class DMA_CHAOSPHYSICS_API ASphereForceField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASphereForceField();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, Category = "Attributes")
	USphereComponent* CollisionMeshForceField;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	float forceF;

	UPROPERTY(VisibleAnywhere, Category = "Attributes")
	FVector forceVectorForceField;
	
	UPROPERTY(VisibleAnywhere, Category = "Attributes")
	TArray<UStaticMeshComponent*> staticMeshArray;
};
