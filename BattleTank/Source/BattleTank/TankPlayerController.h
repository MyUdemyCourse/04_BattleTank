// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyTank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Called Once at BeginPlay.
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:	//Pointer towards controlled tank. 
	AMyTank* GetControlledTank() const;

	void AimTowardsCrosshair();

	//return an OUT parameter, true if hit landspace
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

	//Getting Look Direction 
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	//creating properties for the cross hair location ( 50% across 33%down)
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = .5;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = .33333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
		
};
