// Copyright Epic Games, Inc. All Rights Reserved.


#include "TopDownShooterGameModeBase.h"

void ATopDownShooterGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ATopDownShooterGameModeBase::ActorDied(AActor* DeadActor)
{
	UE_LOG(LogTemp, Warning, TEXT("A actor died: %s"), *DeadActor->GetName());
}

