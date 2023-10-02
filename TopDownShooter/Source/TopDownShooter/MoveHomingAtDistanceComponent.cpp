// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveHomingAtDistanceComponent.h"

void UMoveHomingAtDistanceComponent::Move(float DeltaTime)
{
	if (PlayerPawn == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("MoveHomingAtDistanceComponent: No player pawn found!"));
		return;
	}

	const FVector PlayerLocation = PlayerPawn->GetActorLocation();
	const FVector Location = GetOwner()->GetActorLocation();
	const FVector Direction = PlayerLocation - Location;
	const float Distance = Direction.Size();

	if (Distance <= HomingDistance)
	{
		const FRotator Rotation = Direction.Rotation();
		const FRotator NewRotation = FMath::RInterpTo(GetOwner()->GetActorRotation(), Rotation, DeltaTime,
		                                              HomingRotationSpeed);
		GetOwner()->SetActorRotation(NewRotation);

		const FVector MoveVector = GetOwner()->GetActorForwardVector() * HomingSpeed * DeltaTime;
		GetOwner()->SetActorLocation(Location + MoveVector);
	}
	else
	{
		Super::Move(DeltaTime);
	}
}

void UMoveHomingAtDistanceComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = Cast<APawn>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerPawn == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("MoveHomingAtDistanceComponent: No player pawn found!"));
		return;
	}
}
