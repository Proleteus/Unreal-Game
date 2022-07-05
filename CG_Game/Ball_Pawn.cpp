// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball_Pawn.h"
#include "GameMode_Ball.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
// Sets default values
ABall_Pawn::ABall_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	RootComponent = SceneComponent;
	StaticMesh->SetupAttachment(SceneComponent);
	SpringArm->SetupAttachment(StaticMesh);
	CameraComponent->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	SpringArm->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ABall_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABall_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABall_Pawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABall_Pawn::MoveRight);
	InputComponent->BindAxis("Turn", this, &ABall_Pawn::Turn);
	
}

void ABall_Pawn::MoveForward(float Value)
{
	FName BoneName = TEXT("None");
	FVector ForceVector = CameraComponent->GetForwardVector();
	ForceVector.X = ForceVector.X * Value * 500.0f;
	ForceVector.Y = ForceVector.Y * Value * 500.0f;
	StaticMesh->AddForce(ForceVector, BoneName, true);
}

void ABall_Pawn::MoveRight(float Value)
{
	FName BoneName = TEXT("None");
	FVector ForceVector = CameraComponent->GetRightVector();
	ForceVector.X = ForceVector.X * Value * 500.0f;
	ForceVector.Y = ForceVector.Y * Value * 500.0f;
	StaticMesh->AddForce(ForceVector, BoneName, true);
}

void ABall_Pawn::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ABall_Pawn::AddCoin()
{
	//GameMode_Ball->AddCoin();
}