// Copyright Epic Games, Inc. All Rights Reserved.


#include "CG_GameGameModeBase.h"
#include "Ball_Character.h"
#include "UObject/ConstructorHelpers.h"


ACG_GameGameModeBase::ACG_GameGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyBall_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

}
