// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APlayerController>(GetController());
	PlayerStartLocalPosition = GetActorLocation();
	PlayerRightVector = GetActorRightVector();
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move"), this, &APlayerPawn::Move);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &APlayerPawn::Shoot);
}

void APlayerPawn::Move(const float AxisValue)
{
	const FVector DeltaMovement = AxisValue * Speed * GetWorld()->DeltaTimeSeconds * PlayerRightVector;
	const FVector DesiredLocation = GetActorLocation() + DeltaMovement;

	FVector OffsetFromStart = DesiredLocation - PlayerStartLocalPosition;
	OffsetFromStart.Z = 0.0f;
	const float SquaredDistance = OffsetFromStart.SizeSquared();

	if (const float SquaredMaxDistance = MaxHorizontalDistance * MaxHorizontalDistance; SquaredDistance <= SquaredMaxDistance)
	{
		SetActorLocation(DesiredLocation);
	}
}

void APlayerPawn::Shoot()
{
	
}