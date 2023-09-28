// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TopDownShooterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHOOTER_API ATopDownShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;
	
};
