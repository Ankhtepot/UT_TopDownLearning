// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TOPDOWNSHOOTER_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* SpawnEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Test;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(MakeEditWidget = true))
	USceneComponent* SpawnPoint;

	UPROPERTY(EditAnywhere)
	class TSubclassOf<class ABasePawn> EnemyClass;

	UFUNCTION(BlueprintCallable, Category = "MyInterface")
	void SpawnEnemy();

private:
	UPROPERTY()
	USceneComponent* Root;

	void SetHeightToPlayer();

};
