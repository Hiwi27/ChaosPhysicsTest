// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "BounceActor.generated.h"

class UInputAction;

UCLASS()
class DMA_CHAOSPHYSICS_API ABounceActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABounceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	UStaticMeshComponent* CubeStaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	UStaticMeshComponent* SphereStaticMeshComponent;
	
	UPROPERTY(EditAnywhere, Category = "Attributes")
	UPhysicsConstraintComponent* PhysicsConstraintComponent;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	UBoxComponent* CollisionMeshBounceActor;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	UArrowComponent* FlechaArrowComponent;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	UBoxComponent* BoxCollisionComponent;


	UPROPERTY(EditAnywhere, Category = "Enhaced Input")
	UEnhancedInputComponent* EnhacedInputComponent;

	UPROPERTY(EditAnywhere, Category = "Enhaced Input")
	UInputAction* IA_Action;

private:
	
	UPROPERTY()
	FVector forceVector;

	UPROPERTY(EditAnywhere, Category = "Forces")
	float ConstrainRotationForce;

	UPROPERTY(EditAnywhere, Category = "Forces")
	float BoxReboundForce;

	UPROPERTY()
	TArray<UStaticMeshComponent*> staticMeshArray;

public:
	UFUNCTION()
	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void MoveStick();



};
