// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCombatComponent.h"
#include "../../EnumLibrary/CombatEnums.h"
#include "../../StructLibrary/StructLibrary.h"
#include "../../Items/Armor/ArmorHelper.h"
#include "../../Items/Weapon/AttackLibrary.h"
#include "BaseStatsComponent.h"

// Sets default values for this component's properties
UBaseCombatComponent::UBaseCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBaseCombatComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentAttackPosition = EAttackPosition::EAP_None;
	CurrentDefensePosition = EDefensePosition::EDP_None;
	PreviousDefensePosition = EDefensePosition::EDP_None;

	// ...
	
}
EAttackPosition UBaseCombatComponent::DefensePositionToAttackPosition(EDefensePosition InPosition)
{
	switch (InPosition)
	{
	case EDefensePosition::EDP_None:
		return EAttackPosition::EAP_None;
	case EDefensePosition::EDP_AttackLow:
		return EAttackPosition::EAP_AttackLow;
	case EDefensePosition::EDP_AttackMid:
		return EAttackPosition::EAP_AttackMid;
	case EDefensePosition::EDP_AttackHigh:
		return EAttackPosition::EAP_AttackHigh;
	}
	return EAttackPosition::EAP_None;
}


// Called every frame
void UBaseCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBaseCombatComponent::RecieveAttack(FOutgoingAttackStruct CurrentIncomingAttack)
{
	if (IsValid(OwnerStatsComponent))
	{

		// init
		IncomingAttack = CurrentIncomingAttack;
		EAttackPosition IncomingAttackPosition = IncomingAttack.CurrentAttackPosition;
		EPhysicalDamageType IncomingDamageType = IncomingAttack.AttackPhysicalDamageType;
		EDefensePosition MatchedDefensePosition = EDefensePosition::EDP_None;
		// get hit location
		EBodyPart HitBodyPartType = FAttackHelper::GetLimbFromBone(IncomingAttack.HitBoneName);
		FBodyPartStruct HitBodyPart = OwnerStatsComponent->BodyPartsMap.FindRef(HitBodyPartType);

		FAttackRecievedStruct CurrentDamageValues = FArmorHelper::RecieveAttack(IncomingAttack, HitBodyPart.ArmorBodyPart);

		HitBodyPart.RecieveDamage(CurrentDamageValues.DamageBodyPartStruct);
		HitBodyPart.ArmorBodyPart = CurrentDamageValues.DamagedArmor;
		
		OwnerStatsComponent->UpdateBodyPart(HitBodyPart);
		float DamageToWellbeing = (HitBodyPartType == EBodyPart::EBP_Head || HitBodyPartType == EBodyPart::EBP_Neck || HitBodyPartType == EBodyPart::EBP_Head)
			? CurrentDamageValues.DamageBodyPartStruct.AmountOfDamage : CurrentDamageValues.DamageBodyPartStruct.AmountOfDamage / 4;
		OwnerStatsComponent->MakeDamageValuesFromAttack(DamageToWellbeing, IncomingDamageType);

		// hit reaction
		switch (IncomingAttackPosition)
		{
		case EAttackPosition::EAP_AttackHigh:
			MatchedDefensePosition = EDefensePosition::EDP_AttackHigh;
		case EAttackPosition::EAP_AttackMid:
			MatchedDefensePosition = EDefensePosition::EDP_AttackMid;
		case EAttackPosition::EAP_AttackLow:
			MatchedDefensePosition = EDefensePosition::EDP_AttackLow;
		}
		if (MatchedDefensePosition == CurrentDefensePosition)
		{
			// from here, we will see if the enemy parried or not
			OnHitReactionDecided.Broadcast(EHitReactionCatagory::EHRT_BlockReact);
			return;
		}
		OnHitReactionDecided.Broadcast(EHitReactionCatagory::EHRT_HitStun);
		return;
	}
	return;
}


EAttackPosition UBaseCombatComponent::GetCurrentAttackPosition()
{
	return CurrentAttackPosition;
}

void UBaseCombatComponent::SetCurrentAttackPosition(EAttackPosition NewPosition)
{
	CurrentAttackPosition = NewPosition;
}

EDefensePosition UBaseCombatComponent::GetCurrentDefensePosition()
{
	return CurrentDefensePosition;
}

void UBaseCombatComponent::SetCurrentDefensePosition(EDefensePosition NewPosition)
{
	CurrentDefensePosition = NewPosition;
}