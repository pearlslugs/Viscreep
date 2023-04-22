// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode/GameModeInterface.h"
#include "ViscreepGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VISCREEP_API AViscreepGameModeBase : public AGameModeBase, public IGameModeInterface
{
	GENERATED_BODY()
public:

    AViscreepGameModeBase();

protected:

    virtual void BeginPlay() override;
};
