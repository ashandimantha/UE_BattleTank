// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"

#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Tank Mocement Component Pointer
	UTankAimingComponent* TankAimingComponent = nullptr;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Tank)
		void SetTankStaticMesh(UStaticMeshComponent* TankFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
		void SetTurretChildActor(UChildActorComponent* TurretFromBP);

	UPROPERTY(EditAnywhere, Category = "Tank Movement")
		float TankMovementSpeed = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Tank Movement")
		float TankRotationSpeed = 50.0f;
	
	UPROPERTY(EditAnywhere, Category = "Tank Movement")
		float TurretRotationSpeed = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Tank Movement")
		float BarrelElevationSpeed = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetBarrelReference(UStaticMeshComponent* BarrelToSet);


private:
	// move tank at speed
	void MoveTank(float Speed);
	// Rotate tank at speed
	void RotateTank(float Speed);

	// Rotate Barrel at Speed, Negative values for counter clockwise
	void RotateTurret(float Speed);
	// Elevate Barrel at Speed, Negative values for counter clockwise
	void ElevateBarrel(float Speed);

	// A reference from blueprint
	UStaticMeshComponent* Tank = nullptr;
	UChildActorComponent* Turret = nullptr;
	UStaticMeshComponent* Barrel = nullptr;
};
