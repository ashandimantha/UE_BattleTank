// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
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

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	// Get a cast to AI Player Pawn in the world
	ATank* GetAIControlledTank() const;

	// Get a cast to the Player Pawn in the world
	ATank* GetPlayerTank() const;

public:
	// Set defualt values
	ATankAIController();
};
