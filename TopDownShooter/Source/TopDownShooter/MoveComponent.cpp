// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	if (const APawn* PlayerPawn = Cast<APawn>(GetWorld()->GetFirstPlayerController()->GetPawn()); PlayerPawn != nullptr)
	{
		InitialMoveDirection = PlayerPawn->GetActorForwardVector() * -1;
		InitialMoveDirection.Z = 0.f;
	}
	
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Move(DeltaTime);
}

void UMoveComponent::Move(float DeltaTime)
{
	const FVector Location = GetOwner()->GetActorLocation();
	const FVector MoveVector = InitialMoveDirection * MoveSpeed * DeltaTime;
	// UE_LOG(LogTemp, Warning, TEXT("EnemyMove: DeltaTime: %f, Location: %s, MoveVector: %s"), DeltaTime, *Location.ToString(), *MoveVector.ToString());
	GetOwner()->SetActorLocation(Location + MoveVector);
	// UE_LOG(LogTemp, Warning, TEXT("EnemyMove: NewLocation: %s"), *GetActorLocation().ToString());
	// Log BaseMesh Location and Actor Location
	// UE_LOG(LogTemp, Warning, TEXT("BaseMesh Location: %s, Actor Location: %s"), *BaseMesh->GetComponentLocation().ToString(), *GetActorLocation().ToString());
}

