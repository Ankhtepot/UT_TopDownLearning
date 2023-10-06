// Fill out your copyright notice in the Description page of Project Settings.


#include "CannonPlayerController.h"

#include "Blueprint/UserWidget.h"

void ACannonPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}
