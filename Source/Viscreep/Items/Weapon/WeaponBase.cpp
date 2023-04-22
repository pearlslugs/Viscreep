// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponBase.h"
#include "./AttackLibrary.h"
#include "../../Character/Player/PlayerCharacterInterface.h"
#include "../Components/WeaponCollisionComponent.h"

AWeaponBase::AWeaponBase()
{
	WeaponCollision = CreateDefaultSubobject<UWeaponCollisionComponent>(TEXT("Weapon|Components"));
}

FOutgoingAttackStruct AWeaponBase::MakeAttack(FOutgoingAttackStruct InProgressAttack)
{
	IPlayerCharacterInterface* InterfaceOwner = Cast<IPlayerCharacterInterface>(ActorOwner);
	if (InterfaceOwner)
	{
		FCurrentWeaponScalingValues ScalingInfo = InterfaceOwner->GetScalingInfo();
		return FAttackHelper::MakeOutgoingAttack(WeaponData, ScalingInfo, InProgressAttack);
	}
	return InProgressAttack;
}