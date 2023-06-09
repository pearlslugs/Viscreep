// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseRPGCharacter.h"
#include "BaseNonPlayableCharacter.generated.h"

/**
 * 
 */

class UNPCCombatComponent;

UCLASS()
class VISCREEP_API ABaseNonPlayableCharacter : public ABaseRPGCharacter
{
	GENERATED_BODY()
public:
	ABaseNonPlayableCharacter();
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UNPCCombatComponent* CombatComponent;
	
	void NPCAttack()
	{

	}
	
};
