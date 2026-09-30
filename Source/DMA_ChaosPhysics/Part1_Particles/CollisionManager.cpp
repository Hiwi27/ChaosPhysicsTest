// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionManager.h"

#include "Solid.h"


// Sets default values
ACollisionManager::ACollisionManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACollisionManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollisionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	for (int32 i = 0; i < SolidsToHandle.Num(); i++)
	{
		ASolid* SolidA = SolidsToHandle[i];

		for (int32 j = i + 1; j < SolidsToHandle.Num(); j++)
		{
			ASolid* SolidB = SolidsToHandle[j];

			if(SolidA != SolidB)
			{
				
			
			float DistBetweenElements = FVector::Dist(SolidA->Position, SolidB->Position);

			// Verificar si están colisionando
			if (DistBetweenElements < (SolidA->Radius + SolidB->Radius))
			{
				// Marcar ambos sólidos como colisionando
				SolidA->Colliding = true;
				SolidB->Colliding = true;

				// Calcular el vector normal de la colisión
				FVector CollisionNormal = (SolidB->Position - SolidA->Position).GetSafeNormal();

				// Calcular la velocidad relativa
				FVector RelativeVelocity = SolidB->Velocity - SolidA->Velocity;

				// Calcular la velocidad a lo largo de la dirección normal
				float VelocityAlongNormal = FVector::DotProduct(RelativeVelocity, CollisionNormal);

				// Si las velocidades están separando, saltar
				if (VelocityAlongNormal > 0)
					continue;

				// Calcular el escalar del impulso (sin restitución)
				float ImpulseScalar = -VelocityAlongNormal;
				ImpulseScalar /= (1 / SolidA->Mass + 1 / SolidB->Mass);

				// Aplicar el impulso a la aceleración de cada sólido
				FVector Impulse = ImpulseScalar * CollisionNormal;

				// Modificar la aceleración para reflejar el cambio de momentum
				SolidA->Acceleration -= (1 / SolidA->Mass) * Impulse;
				SolidB->Acceleration += (1 / SolidB->Mass) * Impulse;

				// Corrección de penetración: ajustar posiciones para resolver intersección
				float PenetrationDepth = (SolidA->Radius + SolidB->Radius) - DistBetweenElements;
				FVector PenetrationCorrection = CollisionNormal * (PenetrationDepth / 2);

				SolidA->Position -= PenetrationCorrection;
				SolidB->Position += PenetrationCorrection;
			}
			else
			{
				// Marcar que no están colisionando
				SolidA->Colliding = false;
				SolidB->Colliding = false;
			}
			}

		}
	}
}

