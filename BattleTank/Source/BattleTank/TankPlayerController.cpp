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

	 FVector HitLocation; //this is an OUT parameter.
	 if (GetSightRayHitLocation(HitLocation)) { // Has "side-effect", is goingto line trace.
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
		
		// TODO Tell controlled tank to aim at this point. 

	 }
	
 }
 // Get world location of linetrace through crosshair, true if hits landscape. 
 bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
 {	
	 HitLocation = FVector(1.0); //TODO change to aimcomponent rather than just 1. 
	 return true;
 }
