// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

#include "BasePawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Base Root"));
	RootComponent = Root;

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	SpawnPoint->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	if (SpawnEffect == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No spawn effect found!"));
		return;	
	}

	SetHeightToPlayer();

	UGameplayStatics::SpawnEmitterAtLocation(this, SpawnEffect, GetActorLocation());
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::SetHeightToPlayer()
{
	const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("No player pawn found!"));
		return;
	}

	// const FVector PlayerLocation = PlayerPawn->GetActorLocation();
	// FVector Location = GetActorLocation();
	// UE_LOG(LogTemp, Warning, TEXT("PreChange: %s"), *Location.ToString());
	// Location.Z = PlayerLocation.Z;
	// UE_LOG(LogTemp, Warning, TEXT("PostChange: %s"), *Location.ToString());
	// SetActorLocation(Location);
}

void AEnemySpawner::SpawnEnemy()
{
	if (EnemyClass == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No enemy class found!"));
		return;
	}
	const FVector Location = SpawnPoint->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("Spawn enemy at %s"), *Location.ToString());
	ABasePawn* Enemy = GetWorld()->SpawnActor<ABasePawn>(EnemyClass, Location, FRotator::ZeroRotator);
	
}

