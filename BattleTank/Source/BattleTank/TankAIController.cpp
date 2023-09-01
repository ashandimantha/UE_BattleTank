// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

ATankAIController::ATankAIController()
{

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// Find the first child actor of the player pawn
	auto PlayerController = GetWorld()->GetFirstPlayerController();
	auto PlayerPawn = PlayerController->GetPawn();
	PlayerPawn->GetAttachedActors(ChildActors);
	FirstChildActor = ChildActors[0];

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AIControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// TODO Move AI Tank towards the player

		// Aim towards the player
		AIControlledTank->AimAt(FirstChildActor->GetActorLocation());

		// Fire if ready
		AIControlledTank->Fire();
	}
}

