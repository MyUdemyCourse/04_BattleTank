// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

 AMyTank* ATankPlayerController::GetControlledTank() const {
	return Cast<AMyTank>(GetPawn());
}