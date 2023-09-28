// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"

#include "Engine/DamageEvents.h"

void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();

	// // Gets player pawn and his forward vector and reverse it
	// if (const APawn* PlayerPawn = Cast<APawn>(GetWorld()->GetFirstPlayerController()->GetPawn()); PlayerPawn != nullptr)
	// {
	// 	InitialMoveDirection = PlayerPawn->GetActorForwardVector() * -1;
	// 	InitialMoveDirection.Z = 0.f;
	// }
}

// void AEnemyPawn::Move(float DeltaTime)
// {
	// const FVector Location = GetActorLocation();
	// const FVector MoveVector = InitialMoveDirection * MoveSpeed * DeltaTime;
	// // UE_LOG(LogTemp, Warning, TEXT("EnemyMove: DeltaTime: %f, Location: %s, MoveVector: %s"), DeltaTime, *Location.ToString(), *MoveVector.ToString());
	// SetActorLocation(Location + MoveVector);
	// // UE_LOG(LogTemp, Warning, TEXT("EnemyMove: NewLocation: %s"), *GetActorLocation().ToString());
	// // Log BaseMesh Location and Actor Location
	// // UE_LOG(LogTemp, Warning, TEXT("BaseMesh Location: %s, Actor Location: %s"), *BaseMesh->GetComponentLocation().ToString(), *GetActorLocation().ToString());
// }

void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Move(DeltaTime);
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
}
