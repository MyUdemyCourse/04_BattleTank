// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI is not possessing a tank. "));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AI controlled %s is active."), *ControlledTank->GetName());
	}
}

	AMyTank* ATankAIController::GetControlledTank() const {

	return Cast<AMyTank>(GetPawn());
}