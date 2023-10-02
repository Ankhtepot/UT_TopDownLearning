// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveComponent.h"
#include "MoveHomingAtDistanceComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWNSHOOTER_API UMoveHomingAtDistanceComponent : public UMoveComponent
{
	GENERATED_BODY()

private:
	virtual void Move(float DeltaTime) override;

	virtual void BeginPlay() override;

	UPROPERTY()
	class APawn* PlayerPawn;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HomingDistance = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HomingSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HomingRotationSpeed = 100.f;
	
};
