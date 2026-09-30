// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionActor.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ACollisionActor::ACollisionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add Components
	staticMeshCollisionActor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	// Set Roots
	SetRootComponent(staticMeshCollisionActor);
}

// Called when the game starts or when spawned
void ACollisionActor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> gameManagerInstances;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGameManager::StaticClass(), gameManagerInstances);

	AGameManager* myGameManager = Cast<AGameManager>(gameManagerInstances[0]);

	if (myGameManager)
	{
		gameManager = myGameManager;
	}

	if (staticMeshCollisionActor)
	{
		staticMeshCollisionActor->OnComponentHit.AddDynamic(this, &ACollisionActor::OnHit);
	}

}

// Called every frame
void ACollisionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollisionActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	gameManager->SetScore(gameManager->score + 1);
}