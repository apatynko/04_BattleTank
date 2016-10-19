// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = Tank)
		void SetTankChildActor(UChildActorComponent* TankFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretChildActor(UChildActorComponent* TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
		void SetBarrelChildActor(UChildActorComponent* BarrelFromBP);

private:
	// A TANK reference  from Blueprint
	UChildActorComponent* Tank = nullptr;
	// Move tank at speed, -ve values for CCW
	void MoveTank(float Speed);
	// Rotate tank at speed, -ve values for CCW
	void RotateTank(float Speed);
	
	// A TURRET reference  from Blueprint
	UChildActorComponent* Turret = nullptr;
	// Rotate turret at speed, -ve values for CCW
	void RotateTurret(float Speed);
	
	// A Barrel reference  from Blueprint
	UChildActorComponent* Barrel = nullptr;
	// Rotate Barrel at speed, -ve values for CCW
	void ElevateBarrel(float Speed);
	UPROPERTY(EditAnywhere)
		float RotationSpeed = 120.f;
	UPROPERTY(EditAnywhere)
		float MovementSpeed = 120.f;
};

