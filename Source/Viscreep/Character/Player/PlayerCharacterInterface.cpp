// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterInterface.h"

// Add default functionality here for any IPlayerCharacterInterface functions that are not pure virtual.

TArray<ACharacter*> IPlayerCharacterInterface::GetOverlappingCharacters()
{
	TArray<ACharacter*> fake;
	return fake;
}
FCurrentWeaponScalingValues IPlayerCharacterInterface::GetScalingInfo()
{
	FCurrentWeaponScalingValues fake;
	return fake;
}