// Fill out your copyright notice in the Description page of Project Settings.


#include "ForceField.h"

// Sets default values
AForceField::AForceField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add Components
	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	flecha = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));

	// Set Roots
	SetRootComponent(CollisionMesh);
	flecha->AttachToComponent(CollisionMesh, FAttachmentTransformRules::KeepRelativeTransform);

	//OnCollisionEnterDelegate
	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AForceField::OnBoxBeginOverlap);

	CollisionMesh->OnComponentEndOverlap.AddDynamic(this, &AForceField::OnBoxEndOverlap);

}

// Called when the game starts or when spawned
void AForceField::BeginPlay()
{
	Super::BeginPlay();

	//FRotator fieldRotation = GetActorRotation();

	//ForceFieldDimensions = fieldRotation.RotateVector(ForceFieldDimensions);
	/*ForceFieldDimensions = GetActorLocation();
	ForceFieldDimensions = CollisionMesh->GetScaledBoxExtent();*/
	
	forceVector = flecha->GetForwardVector();
	forceVector = forceVector * force;
	
}

// Called every frame
void AForceField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	for (UStaticMeshComponent* iterator : staticMeshArray)
	{
		//FVector meshLocation = iterator->GetComponentLocation();


		//PosicionFinal = iterator->GetComponentLocation();

		//ForceFieldDimensions.Z = PosicionFinal.Z;
		//ForceFieldDimensions.Y = PosicionFinal.Y;
		////FVector ballToCollisionExtent = ForceFieldDimensions - PosicionFinal;
		////FVector distanceBallToCollision = FVector(ballToCollisionExtent.X * flecha->GetForwardVector().X, ballToCollisionExtent.Y * flecha->GetForwardVector().Y, ballToCollisionExtent.Z * flecha->GetForwardVector().Z)
		//double dotP = FVector::DotProduct(ForceFieldDimensions - PosicionFinal, flecha->GetForwardVector());
		//
		////FVector distance = FVector::Dist(meshLocation, );
		//
		//force = -coeficienteElasticidad * FVector::Dist(PosicionFinal, ForceFieldDimensions);

		//forceVector = forceVector * force;

		iterator->AddForce(forceVector, "", true);
	}
}

void AForceField::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (UStaticMeshComponent* mesh = OtherActor->GetComponentByClass<UStaticMeshComponent>())
	{
		staticMeshArray.Add(mesh);
	}

}

void AForceField::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (UStaticMeshComponent* mesh = OtherActor->GetComponentByClass<UStaticMeshComponent>())
	{
		staticMeshArray.Remove(mesh);
	}

}

