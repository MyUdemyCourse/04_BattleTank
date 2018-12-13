// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

///Creates a function that is called at the beginning of play
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerControlled not possessing a tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerControlled possessing %s"), *ControlledTank->GetName());
	}
}
///Creates a Tick for the controller (tests everyframe)
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController is TICKING"))
	AimTowardsCrosshair();


}
///function that returns the Players controlled tank. 
 AMyTank* ATankPlayerController::GetControlledTank() const {
	return Cast<AMyTank>(GetPawn());
}

 void ATankPlayerController::AimTowardsCrosshair() {
	 if (!GetControlledTank()) { return; }

	 //Get world location if linetrace through crosshair
	 //if it his the landscape
		// Tell controlled tank to aim at this point. 

 }
