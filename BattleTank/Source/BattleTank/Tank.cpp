// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Aiming Component
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	InputComponent->BindAxis("Move_Tank", this, &ATank::MoveTank);
	InputComponent->BindAxis("Rotate_Tank", this, &ATank::RotateTank);

}

// Tank Movement - Forward and Backwards
void ATank::MoveTank(float Speed)
{
	if (!Tank) { return; }
	float Distance = GetWorld()->GetDeltaSeconds() * Speed * TankMovementSpeed;
	Tank->AddRelativeLocation(Tank->GetForwardVector() * Distance);
}

// Tank Movement - Ratation
void ATank::RotateTank(float Speed)
{
	if (!Tank) { return; }
	//Speed = GetWorld()->GetDeltaSeconds()
	float Rotation = GetWorld()->GetDeltaSeconds() * Speed * TankRotationSpeed;
	Tank->AddRelativeRotation(FRotator(0, Rotation, 0));
}

// Set Tank Body
void ATank::SetTankStaticMesh(UStaticMeshComponent* TankFromBP)
{
	if (!TankFromBP) { return; }
	Tank = TankFromBP;
}

// Set Turret from the mesh
void ATank::SetTurretChildActor(UChildActorComponent* TurretFromBP)
{
	if (!TurretFromBP) { return; }
	Turret = TurretFromBP;
	TankAimingComponent->SetTurretReference(TurretFromBP);
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}