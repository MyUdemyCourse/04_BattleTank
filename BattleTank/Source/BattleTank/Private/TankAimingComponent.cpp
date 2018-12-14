// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



//Logging ToHitLocation ( at distance )
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Caluculate the outlaunchvelocity
	bool BHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this, // world context object. 
		OutLaunchVelocity, // velocity
		StartLocation, // start location
		HitLocation, // end location
		LaunchSpeed, // Speed of item
		ESuggestProjVelocityTraceOption::DoNotTrace // Tracing options for debugging
	);

	if (BHaveAimSolution) {
		auto TankName = GetOwner()->GetName();
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//MoveBarrelTowards();
		

	}	// If no solution found do nothing. 	
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	//Work-out difference between current barrel rotation, and AimDirection
	//Move the barrel the right amount this frame
	//Given a max elevation speed, and the frame time. 
	
	
	
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
	
}



