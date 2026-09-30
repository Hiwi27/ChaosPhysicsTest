// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationalParticle.h"


// Sets default values
ARotationalParticle::ARotationalParticle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ARotationalParticle::InitializeRotation(FRotator _AngularVelocity, FRotator _AngularAcceleration)
{
	AngularVelocity = _AngularVelocity;
	AngularAcceleration = _AngularAcceleration;
}

// Called when the game starts or when spawned
void ARotationalParticle::BeginPlay()
{
	Super::BeginPlay();

	Rotation = GetActorRotation();
	
}

// Called every frame
void ARotationalParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AngularVelocity += AngularAcceleration * DeltaTime;
	Rotation += AngularVelocity * DeltaTime;

	SetActorRotation(Rotation);
}

