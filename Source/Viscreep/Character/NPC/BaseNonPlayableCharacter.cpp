// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNonPlayableCharacter.h"
#include "../Components/NPCCombatComponent.h"

ABaseNonPlayableCharacter::ABaseNonPlayableCharacter()
{
	CombatComponent = CreateDefaultSubobject<UNPCCombatComponent>(TEXT("CombatComponent"));
}

