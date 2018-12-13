// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/PlayerController.h" //required for GetWorld() to work
#include "Engine/World.h" //required for GetWorld() to work


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	/*auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI is not possessing a tank. "));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AI controlled %s is active."), *ControlledTank->GetName());
	}*/
	
	///Function to locate which Pawn AI is targeting. 
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI can not locate PlayerPawn. "));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI located %s ."), *PlayerTank->GetName());
	}
};

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {
		//TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController is TICKING"))
	


}

	///fuction to point at AI controlled pawn
	AMyTank* ATankAIController::GetControlledTank() const {

	return Cast<AMyTank>(GetPawn());
}
	/// function to point at a player controlled pawn. 
	AMyTank* ATankAIController::GetPlayerTank() const {
		auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (!PlayerPawn) { return nullptr; }
		return Cast<AMyTank>(PlayerPawn);
	};