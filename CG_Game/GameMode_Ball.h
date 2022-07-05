// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode_Ball.generated.h"

/**
 * 
 */
UCLASS()
class CG_GAME_API AGameMode_Ball : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	AGameMode_Ball();

	UFUNCTION(BlueprintCallable)
		void AddCoin();

	UPROPERTY(VisibleAnywhere)
		int32 TotalCoins = 0;

};
