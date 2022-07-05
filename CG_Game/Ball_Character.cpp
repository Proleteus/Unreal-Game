// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball_Character.h"

// Sets default values
ABall_Character::ABall_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABall_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABall_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &ABall_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABall_Character::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ABall_Character::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ABall_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABall_Character::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABall_Character::StopJump);
}

void ABall_Character::MoveForward(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
	AddActorLocalRotation(FRotator(0, Value, 0));
}

void ABall_Character::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ABall_Character::StartJump()
{
	bPressedJump = true;
}

void ABall_Character::StopJump()
{
	bPressedJump = false;
}