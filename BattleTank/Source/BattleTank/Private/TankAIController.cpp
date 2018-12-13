// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	/*auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI is not possessing a tank. "));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AI controlled %s is active."), *ControlledTank->GetName());
	}*/
	
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI can not locate PlayerPawn. "));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI located %s ."), *PlayerTank->GetName());
	}
};


	AMyTank* ATankAIController::GetControlledTank() const {

	return Cast<AMyTank>(GetPawn());
}

	AMyTank* ATankAIController::GetPlayerTank() const {
		auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (!PlayerPawn) { return nullptr; }
		return Cast<AMyTank>(PlayerPawn);
	};