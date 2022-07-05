// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinActor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/SphereComponent.h"
#include <CG_Game/Ball_Pawn.h>

// Sets default values
ACoinActor::ACoinActor()
{
	fg_bCollected = false;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetupAttachment(SceneComponent);
	SphereCollider->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	SphereCollider->SetGenerateOverlapEvents(true);

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
	CoinMesh->SetupAttachment(SphereCollider);
	CoinMesh->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACoinActor::OnSphereOverlap);
	SphereCollider->AttachToComponent(SceneComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	RotatingMovement->RotationRate = FRotator(0, 180, 0);

}

// Called when the game starts or when spawned
void ACoinActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoinActor::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//ABall_Pawn* BallPawn = Cast<ABall_Pawn>(OtherActor);

	//if (BallPawn)
	//{
	//	/*if (OverlapSound)
	//	{
	//		UGameplayStatics::PlaySoundAtLocaion(GetWorld().OverlpaSound, GetActorLocation());
	//	}*/

	//	BallPawn->AddCoin();

	//	Destroy();
	//}
	Destroy();

	/*if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		fg_bCollected = true;
	}*/
}

void ACoinActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (fg_bCollected == true)
	{
		
		Destroy();
	}
}


