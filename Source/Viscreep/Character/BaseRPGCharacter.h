// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AlsCharacterExample.h"
#include "../StructLibrary/StructLibrary.h"
#include "Interface/RPGInterface.h"
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
class AWeaponBase;

UCLASS()
class VISCREEP_API ABaseRPGCharacter : public AAlsCharacterExample, public IRPGInterface
{
	GENERATED_BODY()


public:
	// Sets default values for this component's properties
	ABaseRPGCharacter();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AWeaponBase* EquippedRightHandWeapon;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldRotateToTarget;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* Input) override;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Components")
	UBaseStatsComponent* CharacterStatsComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Components")
	UHitReactionComponent* CharacterHitReactionComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
	UMontageManagerComponent* CharacterMontageManagerComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Components")
	UCharacterStateComponent* CharacterStateComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Components")
	UInventoryComponent* CharacterInventoryComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Components")
	UEquipmentComponent* CharacterEquipmentComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Components")
	UCharacterPersonalityComponent* CharacterPersonalityComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Components")
	UCharacterHistoryComponent* CharacterHistoryComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Components")
	UStatusEffectComponent* CharacterStatusEffectComponent;
	UFUNCTION(BlueprintCallable)
	FAnimMontageStruct GetAttackAnimationAndSetCombatState(EAllAttackTypes InAttackType, EAttackPosition InAttackPosition);

	virtual USkinnedMeshComponent* GetSkinnedMesh();

	UFUNCTION(BlueprintCallable)
	bool PlayRPGMontage(FAnimMontageStruct MontageStruct);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
