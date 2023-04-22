// Fill out your copyright notice in the Description page of Project Settings.


#include "MontageManagerComponent.h"

// Sets default values for this component's properties
UMontageManagerComponent::UMontageManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	AttackCount = 0;

	// ...
}


// Called when the game starts
void UMontageManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMontageManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMontageManagerComponent::KeepAttackCountInBounds(TArray<FAnimMontageStruct> CurrentAttackTypeMontages)
{
	if (!(CurrentAttackTypeMontages.Num() > AttackCount))
	{
		AttackCount = 0;
	}
}

FAnimMontageStruct UMontageManagerComponent::GetCurrentMontage(EAllAttackTypes InAttackType, EAttackPosition CurrentAttackPosition)
{
	
	auto CurrentAttackTypeMontages = CurrentWeaponMontages.AttackMontages.Find(InAttackType);
	
	FAnimMontageStruct CurrentMontage;
	
	switch (CurrentAttackPosition)
	{
	case EAttackPosition::EAP_AttackHigh:
		UMontageManagerComponent::KeepAttackCountInBounds(CurrentAttackTypeMontages->HighMontages);
		CurrentMontage = CurrentAttackTypeMontages->HighMontages[AttackCount];
		break;
	case EAttackPosition::EAP_AttackMid:
		UMontageManagerComponent::KeepAttackCountInBounds(CurrentAttackTypeMontages->MidMontages);
		CurrentMontage = CurrentAttackTypeMontages->MidMontages[AttackCount];
		break;
	case EAttackPosition::EAP_AttackLow:
		UMontageManagerComponent::KeepAttackCountInBounds(CurrentAttackTypeMontages->LowMontages);
		CurrentMontage = CurrentAttackTypeMontages->LowMontages[AttackCount];
	case EAttackPosition::EAP_KickHigh:
		break;
		UMontageManagerComponent::KeepAttackCountInBounds(CurrentAttackTypeMontages->AlternativeHighMontages);
		CurrentMontage = CurrentAttackTypeMontages->AlternativeHighMontages[AttackCount];
	case EAttackPosition::EAP_KickLow:
		break;
		UMontageManagerComponent::KeepAttackCountInBounds(CurrentAttackTypeMontages->AlternativeLowMontages);
		CurrentMontage = CurrentAttackTypeMontages->AlternativeLowMontages[AttackCount];
	case EAttackPosition::EAP_Shove:
		break;
		UMontageManagerComponent::KeepAttackCountInBounds(CurrentAttackTypeMontages->AlternativeMidMontages);
		CurrentMontage = CurrentAttackTypeMontages->AlternativeMidMontages[AttackCount];
	case EAttackPosition::EAP_None:
		break;
		UMontageManagerComponent::KeepAttackCountInBounds(CurrentAttackTypeMontages->MidMontages);
		CurrentMontage = CurrentAttackTypeMontages->MidMontages[AttackCount];
	}
	AttackCount++;
	return CurrentMontage;
}

void UMontageManagerComponent::InitializeAllWeaponMontages(TMap <EAllWeaponStanceTypes, FWeaponDependantMontages> InMap)
{
		AllWeaponMontages = InMap;
}
void UMontageManagerComponent::UpdateCurrentWeaponMontages(EAllWeaponStanceTypes CurrentWeapon)
{
	CurrentWeaponMontages = AllWeaponMontages.FindRef(CurrentWeapon);
}

TArray<FAnimMontageStruct> UMontageManagerComponent::GetHitreactionMontgeArray(EAttackPosition InPosition, EMeleeSwingDirection CurrentDirection)
{
	switch (InPosition)
	{
	case EAttackPosition::EAP_AttackHigh:
		return CurrentHitReactionMontages.Find(CurrentDirection)->HighMontages;
			break;
	case EAttackPosition::EAP_AttackMid:
		return CurrentHitReactionMontages.Find(CurrentDirection)->MidMontages;
		break;
	case EAttackPosition::EAP_AttackLow:
		return CurrentHitReactionMontages.Find(CurrentDirection)->HighMontages;
	case EAttackPosition::EAP_KickHigh:
		break;
		return CurrentHitReactionMontages.Find(CurrentDirection)->HighMontages;
	case EAttackPosition::EAP_KickLow:
		break;
		return CurrentHitReactionMontages.Find(CurrentDirection)->HighMontages;
	case EAttackPosition::EAP_Shove:
		break;
		return CurrentHitReactionMontages.Find(CurrentDirection)->HighMontages;
	case EAttackPosition::EAP_None:
		break;
		return CurrentHitReactionMontages.Find(CurrentDirection)->HighMontages;
	}
	return CurrentHitReactionMontages.Find(CurrentDirection)->HighMontages;
}