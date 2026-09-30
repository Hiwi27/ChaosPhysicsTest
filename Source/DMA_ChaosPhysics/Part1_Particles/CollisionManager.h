// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionManager.generated.h"

class ASolid;

UCLASS()
class DMA_CHAOSPHYSICS_API ACollisionManager : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category="Attributes")
	TArray<ASolid*> SolidsToHandle;

	
	// Sets default values for this actor's properties
	ACollisionManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
