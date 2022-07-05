// Fill out your copyright notice in the Description page of Project Settings.



#include "GameMode_Ball.h"
#include "Ball_Pawn.h"


AGameMode_Ball::AGameMode_Ball()
{
	DefaultPawnClass = ABall_Pawn::StaticClass();

}

void AGameMode_Ball::AddCoin()
{
	TotalCoins += 1;

	UE_LOG(LogTemp, Warning, TEXT("Total Coins: %d"), TotalCoins);
}
