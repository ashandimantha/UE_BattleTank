// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel;

// Hold Barrel Properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation, float LaunchSpeed);
		
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UChildActorComponent* Turret = nullptr;
	void SetTurretReference(UChildActorComponent* TurretToSet);

private:
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);
};
