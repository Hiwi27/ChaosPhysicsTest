// Fill out your copyright notice in the Description page of Project Settings.


#include "MyParticleEmitter.h"

#include "Particle.h"


// Sets default values
AMyParticleEmitter::AMyParticleEmitter() : LastEmision(0.0f), EmissionTimeStep(0.5f), MinVelocity(0), MaxVelocity(0),
                                           MinAcceleration(0),
                                           MaxAcceleration(0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMyParticleEmitter::SpawnParticles(float DeltaTime)
{
	if(LastEmision > EmissionTimeStep)
	{
		AParticle* myParticle = GetWorld()->SpawnActor<AParticle>(ParticlesToSpawn, this->GetActorLocation(), this->GetActorRotation());
		myParticle->Initialize(FVector(FMath::RandRange(MinVelocity,  MaxVelocity),FMath::RandRange( MinVelocity,  MaxVelocity),FMath::RandRange(MinVelocity,  MaxVelocity)), FVector(FMath::RandRange( MinAcceleration,  MaxAcceleration),FMath::RandRange( MinAcceleration,  MaxAcceleration),FMath::RandRange( MinAcceleration,  MaxAcceleration)));
		myParticles.Add(myParticle);
		LastEmision = 0.0f;
	}
	else
	{
		LastEmision+= DeltaTime;
	}
}


// Called when the game starts or when spawned
void AMyParticleEmitter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyParticleEmitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpawnParticles(DeltaTime);
	
}

