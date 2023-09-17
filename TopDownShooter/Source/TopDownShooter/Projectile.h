// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;
class ULegacyCameraShake;

UCLASS()
class TOPDOWNSHOOTER_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category= "Combat")
	UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category= "Combat")
	UParticleSystemComponent* TrailParticles;

	UPROPERTY(EditAnywhere, Category= "Combat")
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category= "Combat")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category= "Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	           FVector NormalImpulse,
	           const FHitResult& Hit);
};
