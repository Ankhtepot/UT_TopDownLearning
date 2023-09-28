// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "PlayerPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHOOTER_API APlayerPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	APlayerPawn();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	APlayerController* PlayerController;

	UPROPERTY(EditAnywhere)
	float Speed = 100.f;

	UPROPERTY(EditAnywhere)
	float MaxHorizontalDistance = 500.f;

	UPROPERTY()
	FVector PlayerStartLocalPosition;
	FVector PlayerRightVector;

	void Move(float AxisValue);
	void Shoot();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
