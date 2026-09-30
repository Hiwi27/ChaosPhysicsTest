// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleForceField.h"

#include "Particle.h"
#include "RotationalParticle.h"
#include "Solid.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AParticleForceField::AParticleForceField()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add Components
	CollisionMeshForceField = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));

	// Set Roots
	SetRootComponent(CollisionMeshForceField);
	ArrowComponent->AttachToComponent(CollisionMeshForceField, FAttachmentTransformRules::KeepRelativeTransform);


	//OnCollisionEnterDelegate
	CollisionMeshForceField->OnComponentBeginOverlap.AddDynamic(this, &AParticleForceField::OnBoxBeginOverlap);

	CollisionMeshForceField->OnComponentEndOverlap.AddDynamic(this, &AParticleForceField::OnBoxEndOverlap);
	
}

void AParticleForceField::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (ASolid* solid = Cast<ASolid>(OtherActor))
	{
		SolidArray.Add(solid);
	}
	
	if (ARotationalParticle* particle = Cast<ARotationalParticle>(OtherActor))
	{
		RotationParticleArray.Add(particle);
	}
	
	if (AParticle* particle = Cast<AParticle>(OtherActor))
	{
		ParticleArray.Add(particle);
	}

}

void AParticleForceField::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ASolid* solid = Cast<ASolid>(OtherActor))
	{
		SolidArray.Remove(solid);
	}

	if (ARotationalParticle* particle = Cast<ARotationalParticle>(OtherActor))
	{
		RotationParticleArray.Remove(particle);
	}
	
	if (AParticle* particle = Cast<AParticle>(OtherActor))
	{
		ParticleArray.Remove(particle);
	}
}

// Called when the game starts or when spawned
void AParticleForceField::BeginPlay()
{
	Super::BeginPlay();

	ForceDirection = ArrowComponent->GetForwardVector();
	
}

// Called every frame
void AParticleForceField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (ASolid* Element : SolidArray)
	{
		FVector Acceleration = (Force/Element->Mass) * ForceDirection;
		
		Element->Acceleration +=  Acceleration;
	}

	for (AParticle* Element : ParticleArray)
	{
		FVector Acceleration = (Force/Element->Mass) * ForceDirection;
		
		Element->Acceleration +=  Acceleration;
	}

	for (ARotationalParticle* Element : RotationParticleArray)
	{
		FVector Acceleration = (Force/Element->Mass) * ForceDirection;
		
		Element->Acceleration +=  Acceleration;

		// Calcula la fuerza angular (supongamos que aplicas una fuerza en algún punto fuera del centro de masa)
		FVector Torque = FVector::CrossProduct(Element->GetActorLocation(), ForceDirection);

		// Calcula la aceleración angular
		FVector AngularAccelerationVec = Torque / Element->Inertia; 

		FRotator AngularAcceleration(AngularAccelerationVec.Y, AngularAccelerationVec.Z, AngularAccelerationVec.X);

		// Añade la aceleración angular
		Element->AngularAcceleration += AngularAcceleration;
	}
}

