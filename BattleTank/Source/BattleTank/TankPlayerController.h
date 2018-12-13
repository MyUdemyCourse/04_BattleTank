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
	AMyTank* GetControlledTank() const;

	virtual void BeginPlay() override;
	
};
