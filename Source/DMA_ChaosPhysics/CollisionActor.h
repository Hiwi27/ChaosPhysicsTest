// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.h"
#include "CollisionActor.generated.h"

UCLASS()
class DMA_CHAOSPHYSICS_API ACollisionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollisionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	UStaticMeshComponent* staticMeshCollisionActor;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	AGameManager* gameManager;



	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
