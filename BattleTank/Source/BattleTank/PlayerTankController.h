// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerTankController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API APlayerTankController : public APlayerController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	ATank* GetControlledTank() const;

	UPROPERTY(EditAnywhere)
		float CrosshairLocationX = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairLocationY = 0.3333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

public:
	// Strat the tank moving the barrel to the crosshair position
	void AimTowrdsCrosshair();

	// Return the ray hit location
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
