// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	UE_LOG(LogTemp, Warning, TEXT("SetupPlayerInputComponent Called"));
	InputComponent->BindAction("Turret_Clockwise", IE_Pressed, this, &ATank::RotateCW);
	InputComponent->BindAction("Turret_Counterclockwise", IE_Pressed, this, &ATank::RotateCCW);
	
}

void ATank::RotateCW()
{
	UE_LOG(LogTemp, Warning, TEXT("RotateCW Called"));
	Turret->SetRelativeRotation(FRotator(0, 45.f, 0));
	
}

void ATank::RotateCCW()
{
	UE_LOG(LogTemp, Warning, TEXT("RotateCCW Called"));
	Turret->SetRelativeRotation(FRotator(0, -45.f, 0));
}
void ATank::SetTurretChildActor(UChildActorComponent* TurretFromBP)
{
	UE_LOG(LogTemp, Warning, TEXT("SetTurretChildActor Called"));
	Turret = TurretFromBP;
}
