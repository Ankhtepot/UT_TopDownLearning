// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "TopDownShooterGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
	TopDownShooterGameModeBase = Cast<ATopDownShooterGameModeBase>(UGameplayStatics::GetGameMode(this));
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.f || Health <= 0.f)
		return;

	Health = FMath::Clamp(Health - Damage, 0.f, MaxHealth);
	
	UE_LOG(LogTemp, Warning, TEXT("DamageTaken! Health: %f"), Health);

	if (TopDownShooterGameModeBase && Health <= .0f)
	{
		TopDownShooterGameModeBase->ActorDied(DamagedActor);
	}
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

