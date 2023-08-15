// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declerations
class UTankBarrel;
class UTankAimingComponent;

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

	UFUNCTION(BlueprintCallable, Category = Tank)
		void SetBarrelReference(UTankBarrel* BarrelToSet);


private:
	// move tank at speed
	void MoveTank(float Speed);
	// Rotate tank at speed
	void RotateTank(float Speed);

	// A reference from blueprint
	UStaticMeshComponent* Tank = nullptr;
	UChildActorComponent* Turret = nullptr;
	UStaticMeshComponent* Barrel = nullptr;

	// Projectile Launch Speed
	UPROPERTY(EditAnywhere, Category = "Firing Config")
		float LaunchSpeed = 100000.0f; // 1000m/s
};
