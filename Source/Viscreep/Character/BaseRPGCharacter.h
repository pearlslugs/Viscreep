// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AlsCharacter.h"
#include "../StructLibrary/StructLibrary.h"
#include "BaseRPGCharacter.generated.h" 
/**
 *  public AAlsCharacter
 */

 /********************
 *    Declarations   *
 *					 *
 *********************/
class UBaseStatsComponent;
class UHitReactionComponent;
class UMontageManagerComponent;
class UCharacterStateComponent;
class UInventoryComponent;
class UEquipmentComponent;
class UCharacterPersonalityComponent;
class UCharacterHistoryComponent;
class UStatusEffectComponent;

UCLASS()
class VISCREEP_API ABaseRPGCharacter : public AAlsCharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this component's properties
	ABaseRPGCharacter();
	UBaseStatsComponent* CharacterStatsComponent;
	UHitReactionComponent* CharacterHitReactionComponent;
	UMontageManagerComponent* CharacterMontageManagerComponent;
	UCharacterStateComponent* CharacterStateComponent;
	UInventoryComponent* CharacterInventoryComponent;
	UEquipmentComponent* CharacterEquipmentComponent;
	UCharacterPersonalityComponent* CharacterPersonalityComponent;
	UCharacterHistoryComponent* CharacterHistoryComponent;
	UStatusEffectComponent* CharacterStatusEffectComponent;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
};
