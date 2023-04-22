// Derivitave work of https://www.unrealengine.com/marketplace/en-US/profile/AshenGameStudios?count=20&sortBy=effectiveDate&sortDir=DESC&start=0


#include "BaseRPGCharacter.h"
#include "Components/BaseStatsComponent.h"
#include "Components/HitReactionComponent.h"
#include "Components/MontageManagerComponent.h"
#include "Components/CharacterStateComponent.h"
#include "Components/InventoryComponent.h"
#include "Components/EquipmentComponent.h"
#include "Components/CharacterPersonalityComponent.h"
#include "Components/CharacterPersonalityComponent.h"
#include "Components/CharacterHistoryComponent.h"
#include "Components/StatusEffectComponent.h"

// Sets default values for this component's properties
ABaseRPGCharacter::ABaseRPGCharacter()
{
	CharacterMontageManagerComponent = CreateDefaultSubobject<UMontageManagerComponent>(TEXT("CharacterMontageManagerComponentUnCursed"));
	CharacterStatsComponent = CreateDefaultSubobject<UBaseStatsComponent>(TEXT("CharacterStatsComponent"));
	CharacterHitReactionComponent = CreateDefaultSubobject<UHitReactionComponent>(TEXT("CharacterHitReactionComponent"));
	CharacterStateComponent = CreateDefaultSubobject<UCharacterStateComponent>(TEXT("CharacterStateComponent"));
	CharacterInventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("CharacterInventoryComponent"));
	CharacterEquipmentComponent = CreateDefaultSubobject<UEquipmentComponent>(TEXT("CharacterEquipmentComponent"));
	CharacterPersonalityComponent = CreateDefaultSubobject<UCharacterPersonalityComponent>(TEXT("CharacterPersonalityComponent"));
	CharacterHistoryComponent = CreateDefaultSubobject<UCharacterHistoryComponent>(TEXT("CharacterHistoryComponent"));
	CharacterStatusEffectComponent = CreateDefaultSubobject<UStatusEffectComponent>(TEXT("CharacterStatusEffectComponent"));
}

// Called when the game starts
void ABaseRPGCharacter::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void ABaseRPGCharacter::SetupPlayerInputComponent(UInputComponent* Input)
{
	Super::SetupPlayerInputComponent(Input);
}


// Called every frame
void ABaseRPGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ...
}

bool ABaseRPGCharacter::PlayRPGMontage(FAnimMontageStruct MontageStruct)
{
	if(IsValid(MontageStruct.MontageToPlay))
	{
		PlayAnimMontage(MontageStruct.MontageToPlay, MontageStruct.PlayRate);
		// timer to reset character based to reset time
		return true;
	}
	else
	{
		return false;
	}
}

USkinnedMeshComponent* ABaseRPGCharacter::GetSkinnedMesh()
{
	return GetMesh();
}

FAnimMontageStruct ABaseRPGCharacter::GetAttackAnimationAndSetCombatState(EAllAttackTypes InAttackType, EAttackPosition InAttackPosition)
{
		CharacterStateComponent->UpdateCombatState(ECombatState::ECS_Attacking);
		return CharacterMontageManagerComponent->GetCurrentMontage(InAttackType, InAttackPosition);
}