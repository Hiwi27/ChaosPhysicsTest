// Fill out your copyright notice in the Description page of Project Settings.


#include "BounceActor.h"
#include "EnhancedInputComponent.h"

// Sets default values
ABounceActor::ABounceActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	CubeStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeStaticMesh"));
	SphereStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereStaticMesh"));
	FlechaArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	PhysicsConstraintComponent = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("Constrain"));
	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	
	// Set Roots
	SetRootComponent(SceneComponent);

	CubeStaticMeshComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SphereStaticMeshComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FlechaArrowComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	PhysicsConstraintComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollisionComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);

	CubeStaticMeshComponent->SetSimulatePhysics(true);

	//OnCollisionEnterDelegate
	BoxCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABounceActor::OnBoxBeginOverlap);

	BoxCollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ABounceActor::OnBoxEndOverlap);
}

// Called when the game starts or when spawned
void ABounceActor::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(GetWorld()->GetFirstPlayerController()->InputComponent);

	Input->BindAction(IA_Action, ETriggerEvent::Triggered, this, &ABounceActor::MoveStick);

	forceVector = FlechaArrowComponent->GetForwardVector();
	forceVector = forceVector * BoxReboundForce;
}

// Called every frame
void ABounceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (UStaticMeshComponent* iterator : staticMeshArray)
	{
		iterator->AddForce(forceVector, "", true);
	}
}

void ABounceActor::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (UStaticMeshComponent* mesh = OtherActor->GetComponentByClass<UStaticMeshComponent>())
	{
		staticMeshArray.Add(mesh);
	}

}

void ABounceActor::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (UStaticMeshComponent* mesh = OtherActor->GetComponentByClass<UStaticMeshComponent>())
	{
		staticMeshArray.Remove(mesh);
	}

}

void ABounceActor::MoveStick()
{
	GEngine->AddOnScreenDebugMessage(0, 15.0f, FColor::Red, "Moving Stick");
	// FVector ActorLocation = GetActorLocation();
	// FVector direction = FVector(ActorLocation.X + FlechaArrowComponent->GetComponentLocation().X ,ActorLocation.Y,ActorLocation.Z) - ActorLocation;
	// direction.Normalize();
	CubeStaticMeshComponent->AddForce(FlechaArrowComponent->GetForwardVector() * ConstrainRotationForce,"", true);
}
