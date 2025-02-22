// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyTank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	
private:
	// Called Once at BeginPlay.
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Pointer towards AI Pawn.
	AMyTank* GetControlledTank() const;
	//Pointer towards Controlled Pawn. 
	AMyTank* GetPlayerTank() const;

};
