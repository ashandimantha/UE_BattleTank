// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Aiming Component
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	InputComponent->BindAxis("Rotate_Turret", this, &ATank::RotateTurret);
	InputComponent->BindAxis("Elevate_Barrel", this, &ATank::ElevateBarrel);
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

// Tank Turret Movement
void ATank::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	float Rotation = GetWorld()->GetDeltaSeconds() * Speed * TurretRotationSpeed;
	Turret->AddRelativeRotation(FRotator(0, Rotation, 0));

}

// Tank Turret Barrel Movement
void ATank::ElevateBarrel(float Speed)
{
	if (!Barrel) { return; }
	float Rotation = GetWorld()->GetDeltaSeconds() * Speed * BarrelElevationSpeed;
	Barrel->AddRelativeRotation(FRotator(Rotation, 0, 0));
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
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation);
}

void ATank::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}