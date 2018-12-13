// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "GameFramework/PlayerController.h" //required for GetWorld() to work
#include "Engine/World.h" //required for GetWorld() to work


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
		GetControlledTank()->AimAt(HitLocation);
		
		// TODO Tell controlled tank to aim at this point. 

	 }
	
 }
 // Get world location of linetrace through crosshair, true if hits landscape. 
 bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
 {	
	 //Find the crosshair position in pixel coordinates
	 int32 ViewportSizeX, ViewportSizeY;
	 GetViewportSize(ViewportSizeX, ViewportSizeY);  // getting viewport size ( screen size )
	 
	 ///creating a 2D vector to find where something is on the screen ( our crosshair )
	 auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	 
	 //"De-project" the screen position of the crosshair to a world direction.
	 FVector LookDirection;
	 if (GetLookDirection(ScreenLocation, LookDirection)) {
		 // line-trace along that look direction, and see what we hit (up to max range)
		 GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	 
	 //HitLocation = FVector(1.0); //TODO change to aimcomponent rather than just 1. 
	 return true;
 }
 /// Creating a linetrace, with hit location max at 10km ( or 1000000cm)
 bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {
	 FHitResult HitResult;
	 auto StartLocation = PlayerCameraManager->GetCameraLocation();
	 auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	 if(GetWorld()->LineTraceSingleByChannel(
		 HitResult,
		 StartLocation,
		 EndLocation,
		 ECollisionChannel::ECC_Visibility)
		 ){
		 HitLocation = HitResult.Location;
		 return true;
		 }
	 HitLocation = FVector (0);
		 return false; // LineTrance didn't hit anything
 }

 ///Refactored Deprojection function for above function.
 bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	 FVector CameraWorldLocation; // TODO to be discarded
	 return DeprojectScreenPositionToWorld(ScreenLocation.X,
		 ScreenLocation.Y,
		 CameraWorldLocation,
		 LookDirection);
	
 }