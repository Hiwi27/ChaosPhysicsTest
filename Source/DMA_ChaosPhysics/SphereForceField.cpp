// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereForceField.h"

// Sets default values
ASphereForceField::ASphereForceField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add Components
	CollisionMeshForceField = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));

	// Set Roots
	SetRootComponent(CollisionMeshForceField);

	//OnCollisionEnterDelegate
	CollisionMeshForceField->OnComponentBeginOverlap.AddDynamic(this, &ASphereForceField::OnBoxBeginOverlap);

	CollisionMeshForceField->OnComponentEndOverlap.AddDynamic(this, &ASphereForceField::OnBoxEndOverlap);

}

// Called when the game starts or when spawned
void ASphereForceField::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASphereForceField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (UStaticMeshComponent* iterator : staticMeshArray)
	{
		forceVectorForceField = iterator->GetComponentLocation() - GetActorLocation();
		forceVectorForceField.Normalize();
		forceVectorForceField = forceVectorForceField * forceF;
		iterator->AddForce(forceVectorForceField, "", true);
	}

}

void ASphereForceField::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (UStaticMeshComponent* mesh = OtherActor->GetComponentByClass<UStaticMeshComponent>())
	{
		staticMeshArray.Add(mesh);
	}

}

void ASphereForceField::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//force = -2.673f * 

	if (UStaticMeshComponent* mesh = OtherActor->GetComponentByClass<UStaticMeshComponent>())
	{
		staticMeshArray.Remove(mesh);
	}

}
