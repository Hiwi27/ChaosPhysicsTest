// Fill out your copyright notice in the Description page of Project Settings.


#include "ToggleCollisionActor.h"

// Sets default values
AToggleCollisionActor::AToggleCollisionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add Components
	staticMeshToggleCollision = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	// Set Roots
	SetRootComponent(staticMeshToggleCollision);


	HasToBlock = false;

	staticMeshToggleCollision->OnComponentBeginOverlap.AddDynamic(this, &AToggleCollisionActor::OnBoxBeginOverlap);

	staticMeshToggleCollision->OnComponentEndOverlap.AddDynamic(this, &AToggleCollisionActor::OnBoxEndOverlap);
}

// Called when the game starts or when spawned
void AToggleCollisionActor::BeginPlay()
{
	Super::BeginPlay();

	staticMeshToggleCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

}

// Called every frame
void AToggleCollisionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AToggleCollisionActor::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UStaticMeshComponent* mesh = OtherActor->GetComponentByClass<UStaticMeshComponent>())
	{
		HasToBlock = true;
	}	
}

void AToggleCollisionActor::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (UStaticMeshComponent* mesh = OtherActor->GetComponentByClass<UStaticMeshComponent>())
	{
		if (HasToBlock)
		{
			staticMeshToggleCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			staticMeshToggleCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
		}
	}
}

