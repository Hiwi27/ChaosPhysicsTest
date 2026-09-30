// Fill out your copyright notice in the Description page of Project Settings.


#include "Particle.h"


// Sets default values
AParticle::AParticle() : TimeAlive(0.0f), Mass(0.0f), LifeSpan(5.0f)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	
	SetRootComponent(SceneComponent);

	StaticMeshComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AParticle::Initialize(FVector _Velocity, FVector _Acceleration)
{
	Velocity = _Velocity;
	Acceleration = _Acceleration;
}

// Called when the game starts or when spawned
void AParticle::BeginPlay()
{
	Super::BeginPlay();
	Position = GetActorLocation();

	Inertia = (2*Mass)/5;
}

// Called every frame
void AParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(TimeAlive > LifeSpan)
	{
		this->Destroy();
	}
	else
	{
		// Acumular la velocidad en base a la aceleración
		Velocity += Acceleration * DeltaTime;
		
		// Actualizar la posición en base a la velocidad acumulada
		Position += Velocity * DeltaTime;
		
		SetActorLocation(Position);
		TimeAlive += DeltaTime;
	}
	
}

