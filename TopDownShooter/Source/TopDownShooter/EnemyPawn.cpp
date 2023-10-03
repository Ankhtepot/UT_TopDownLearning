// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"

#include "HealthComponent.h"
#include "TopDownShooterGameModeBase.h"
#include "Engine/DamageEvents.h"

AEnemyPawn::AEnemyPawn()
{
	// PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyPawn::OnOverlapWithPlayer(const FVector& Vector, APlayerPawn* PlayerPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("EnemyPawn: Overlap with player!"));
	if (PlayerPawn == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("EnemyPawn: No player pawn found!"));
		return;
	}

	PlayerPawn->TakeDamage(ContactDamage, FDamageEvent(), nullptr, this);

	if (const ATopDownShooterGameModeBase* GameMode = Cast<ATopDownShooterGameModeBase>(GetWorld()->GetAuthGameMode());
		GameMode != nullptr)
	{
		GameMode->ActorDied(this);
	}
}
