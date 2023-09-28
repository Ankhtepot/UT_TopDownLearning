// Copyright Epic Games, Inc. All Rights Reserved.


#include "TopDownShooterGameModeBase.h"

#include "EnemyPawn.h"
#include "Kismet/GameplayStatics.h"

void ATopDownShooterGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ATopDownShooterGameModeBase::ActorDied(AActor* DeadActor) const
{
	UE_LOG(LogTemp, Warning, TEXT("A actor died: %s"), *DeadActor->GetName());

	ABasePawn* BasePawn = Cast<ABasePawn>(DeadActor);
	
	if (BasePawn == nullptr)
	{
		return;
	}
	
	if (BasePawn->DeathParticles != nullptr)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, BasePawn->DeathParticles, BasePawn->GetActorLocation());
	}

	if (BasePawn->DeathSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, BasePawn->DeathSound, BasePawn->GetActorLocation());
	}

	if (const AEnemyPawn* Enemy = Cast<AEnemyPawn>(DeadActor); Enemy != nullptr)
	{
		// TODO: Handle enemy death
	}

	BasePawn->HandleDestruction();
}
