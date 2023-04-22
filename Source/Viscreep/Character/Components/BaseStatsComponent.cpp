// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseStatsComponent.h"
#include "../Components/BaseCombatComponent.h"
#include "Containers/Map.h"
#include "Math/UnrealMathUtility.h"
#include "Templates/Tuple.h"
#include "../../StructLibrary/StructLibrary.h"

// Sets default values for this component's properties
UBaseStatsComponent::UBaseStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	StatsWeaponData.DamageTypeMap.Add(EPhysicalDamageType::EPDT_Slash, 9);

	// ...
}


// Called when the game starts
void UBaseStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UBaseStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UBaseStatsComponent::InitializeStats()
{
	// get stats from game mode, if no game mode stats, I will initialize them here as I do not have any save system yet
}

void UBaseStatsComponent::GetWeaponDamageForAttack()
{

}

FOutgoingAttackStruct UBaseStatsComponent::MakeOutgoingAttack()
{
	StatsWeaponData.DamageTypeMap.Add(EPhysicalDamageType::EPDT_Slash, 9);
	FOutgoingAttackStruct NewAttack;
	NewAttack.TraceInfo = CurrentAttackInfo.TraceInfo;
	NewAttack = FAttackHelper::MakeOutgoingAttack(StatsWeaponData, CurrentWeaponScalingValues, CurrentAttackInfo);
	return NewAttack;
}

void UBaseStatsComponent::OnMeleeHit(AActor* HitActor, FHitTraceResults HitInfo)
{
		CurrentAttackInfo = UBaseStatsComponent::MakeOutgoingAttack();
		CurrentAttackInfo.HitLocation = HitInfo.HitLocation;
		CurrentAttackInfo.HitBoneName = HitInfo.HitBone;
		UBaseCombatComponent* EnemyCombatComponent = HitActor->FindComponentByClass<UBaseCombatComponent>();
		EnemyCombatComponent->RecieveAttack(CurrentAttackInfo);
}

void UBaseStatsComponent::CheckForBleeding()
{
	for (const TPair<EBodyPart, FBodyPartStruct>& BodyPart : BodyPartsMap)
	{
		EBleedingAmount BleedingAmount = BodyPart.Value.BleedingAmount;
		if (BleedingAmount != EBleedingAmount::EBA_None)
		{
			Isbleeding = true;
			float OverAllHealth = CharacterWellbeingMap.FindRef(EWellbeingStats::EWS_OverallHealth);
			switch (BleedingAmount)
			{
			case EBleedingAmount::EBA_Light:
				CharacterWellbeingMap.Add(EWellbeingStats::EWS_OverallHealth, OverAllHealth - 1.f);
				break;
			case EBleedingAmount::EBA_Medium:
				CharacterWellbeingMap.Add(EWellbeingStats::EWS_OverallHealth, OverAllHealth - 4.f);
				break;
			case EBleedingAmount::EBA_Heavy:
				CharacterWellbeingMap.Add(EWellbeingStats::EWS_OverallHealth, OverAllHealth - 8.f);
				break;
			}
			
		}
	}
	if (!Isbleeding)
	{
		// pause timer
	}
}

void UBaseStatsComponent::InitializeWeaponData(AWeaponBase* InWeapon, FWeaponData InWeaponData, float DamageValue)
{
	StatsWeaponData = InWeaponData;
	StatsWeaponData.DamageTypeMap.Add(EPhysicalDamageType::EPDT_Slash, 8);
	InWeapon->WeaponCollision->OnWeaponHitActor.AddDynamic(this, &ThisClass::OnMeleeHit);
	InWeapon->SetActorOwner(GetOwner());
	
	float StrengthScalingEfficiency = StatsWeaponData.StatsScalingMap.FindRef(ECharacterStats::ECS_Strength);
	float DexterityScalingEfficiency = StatsWeaponData.StatsScalingMap.FindRef(ECharacterStats::ECS_Dextarity);
	float TotalStrengthScaling = StrengthCurve->GetFloatValue(StatsMap.FindRef(ECharacterStats::ECS_Strength)) * StrengthScalingEfficiency;
	float TotalDexterityScaling = DexterityCurve->GetFloatValue(StatsMap.FindRef(ECharacterStats::ECS_Dextarity)) * DexterityScalingEfficiency;
	CurrentWeaponScalingValues.Dexterity = TotalDexterityScaling;
	CurrentWeaponScalingValues.Strength = TotalStrengthScaling;
}
void UBaseStatsComponent::MakeDamageValuesFromAttack(float AmountOfDamage, EPhysicalDamageType InDamageType)
{	
	FDamageWellbeingStruct OverAllDamage;
	FDamageWellbeingStruct PainLevel;
	FDamageWellbeingStruct Composure;
	TArray<FDamageWellbeingStruct> DamageToDeal;
	switch (InDamageType)
	{
	case EPhysicalDamageType::EPDT_Blunt:
		OverAllDamage.AmountOfDamage = AmountOfDamage;
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_OverallHealth;
		OverAllDamage.AmountOfDamage = AmountOfDamage * FMath::RandRange(0.25f, 0.6f);
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_PainLevel;
		OverAllDamage.AmountOfDamage = AmountOfDamage * FMath::RandRange(0.4f, 0.6f);
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_Composure;
		DamageToDeal.Add(OverAllDamage);
		DamageToDeal.Add(PainLevel);
		DamageToDeal.Add(Composure);
		UBaseStatsComponent::DamageWellbeingStat(DamageToDeal);
		break;
	case EPhysicalDamageType::EPDT_Hack:
		OverAllDamage.AmountOfDamage = AmountOfDamage;
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_OverallHealth;
		OverAllDamage.AmountOfDamage = AmountOfDamage * FMath::RandRange(0.4f, 0.8f);
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_PainLevel;
		OverAllDamage.AmountOfDamage = AmountOfDamage * FMath::RandRange(0.1f, 0.3f);
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_Composure;
		DamageToDeal.Add(OverAllDamage);
		DamageToDeal.Add(PainLevel);
		DamageToDeal.Add(Composure);
		UBaseStatsComponent::DamageWellbeingStat(DamageToDeal);
		break;
	case EPhysicalDamageType::EPDT_Pierce:
		OverAllDamage.AmountOfDamage = AmountOfDamage;
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_OverallHealth;
		OverAllDamage.AmountOfDamage = AmountOfDamage * FMath::RandRange(0.5f, 0.8f);
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_PainLevel;
		DamageToDeal.Add(OverAllDamage);
		DamageToDeal.Add(PainLevel);
		UBaseStatsComponent::DamageWellbeingStat(DamageToDeal);
		break;
	case EPhysicalDamageType::EPDT_Slash:
		OverAllDamage.AmountOfDamage = AmountOfDamage;
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_OverallHealth;
		OverAllDamage.AmountOfDamage = AmountOfDamage * FMath::RandRange(0.3f, 0.6f);
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_PainLevel;
		OverAllDamage.AmountOfDamage = AmountOfDamage * FMath::RandRange(0.3f, 0.6f);
		OverAllDamage.WellbeingStatToDamage = EWellbeingStats::EWS_Composure;
		DamageToDeal.Add(OverAllDamage);
		DamageToDeal.Add(PainLevel);
		DamageToDeal.Add(Composure);
		UBaseStatsComponent::DamageWellbeingStat(DamageToDeal);
		break;
		case EPhysicalDamageType::EPDT_Composure:
			break;
	}
	DamageToDeal.Empty();
}

void UBaseStatsComponent::DamageWellbeingStat(TArray<FDamageWellbeingStruct> InDamageValues)
{
	for (auto InDamageValue : InDamageValues)
	{
		//Make rules for pain to damage to bleeding ratios
		float CurrentStatValue = CharacterWellbeingMap.FindRef(InDamageValue.WellbeingStatToDamage);
		CharacterWellbeingMap.Add(InDamageValue.WellbeingStatToDamage, CurrentStatValue = CurrentStatValue - InDamageValue.AmountOfDamage);
	}
}