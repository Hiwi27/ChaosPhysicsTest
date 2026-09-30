// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationalParticleEmitter.h"

#include "RotationalParticle.h"


// Sets default values
ARotationalParticleEmitter::ARotationalParticleEmitter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ARotationalParticleEmitter::SpawnParticles(float DeltaTime)
{
	if(LastEmision > EmissionTimeStep)
	{
		ARotationalParticle* myParticle = GetWorld()->SpawnActor<ARotationalParticle>(ParticlesToSpawn, this->GetActorLocation(), this->GetActorRotation());
		myParticle->Initialize(FVector(FMath::RandRange(MinVelocity,  MaxVelocity),FMath::RandRange( MinVelocity,  MaxVelocity),FMath::RandRange(MinVelocity,  MaxVelocity)), FVector(FMath::RandRange( MinAcceleration,  MaxAcceleration),FMath::RandRange( MinAcceleration,  MaxAcceleration),FMath::RandRange( MinAcceleration,  MaxAcceleration)));
		myParticle->InitializeRotation(FRotator(FMath::RandRange(MinAngularVelocity,  MaxAngularVelocity),FMath::RandRange( MinAngularVelocity,  MaxAngularVelocity),FMath::RandRange(MinAngularVelocity,  MaxAngularVelocity)), FRotator(FMath::RandRange( MinAngularAcceleration,  MaxAngularAcceleration),FMath::RandRange( MinAngularAcceleration,  MaxAngularAcceleration),FMath::RandRange( MinAngularAcceleration,  MaxAngularAcceleration)));
		myParticles.Add(myParticle);
		LastEmision = 0.0f;
	}
	else
	{
		LastEmision+= DeltaTime;
	}

	
}


// Called when the game starts or when spawned
void ARotationalParticleEmitter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotationalParticleEmitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

