// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "ForceField.generated.h"

UCLASS()
class DMA_CHAOSPHYSICS_API AForceField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AForceField();

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
	UBoxComponent* CollisionMesh;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	UArrowComponent* flecha;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	float force;

	UPROPERTY(VisibleAnywhere, Category = "Attributes")
	FVector forceVector;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	float coeficienteElasticidad;
	
	FVector ForceFieldDimensions;
	FVector PosicionFinal;
	
	UPROPERTY()
	TArray<UStaticMeshComponent*> staticMeshArray;
};
