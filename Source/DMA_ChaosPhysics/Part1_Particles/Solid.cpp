// Fill out your copyright notice in the Description page of Project Settings.


#include "Solid.h"

#include "DrawDebugHelpers.h"

// Sets default values
ASolid::ASolid():  Mass(0.0f), Colliding(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
		
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	
	SetRootComponent(SceneComponent);

	StaticMeshComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ASolid::BeginPlay()
{
	Super::BeginPlay();

	Position = GetActorLocation();

	Inertia = (2*Mass)/5;
	
}

// Called every frame
void ASolid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Acumular la velocidad en base a la aceleración
	Velocity += Acceleration * DeltaTime;
		
	// Actualizar la posición en base a la velocidad acumulada
	Position += Velocity * DeltaTime;
		
	SetActorLocation(Position);

	if(Colliding == false)
	{
		DrawDebugSphere(GetWorld(), Position, Radius, 32, FColor::Green);
	}
	else
	{
		DrawDebugSphere(GetWorld(), Position, Radius, 32, FColor::Red);
	}
}

