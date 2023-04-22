// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseRPGCharacter.h"
#include "PlayerCharacterInterface.h"
#include "PlayerCharacter.generated.h"

 /********************
 *    Declarations   *
 *					 *
 *********************/

class UInputBufferComponent;
class UCombatComponent;
// init player interface
UCLASS()
class VISCREEP_API APlayerCharacter : public ABaseRPGCharacter, public IPlayerCharacterInterface
{
	GENERATED_BODY()
	APlayerCharacter();

public:
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
	UInputBufferComponent* PlayerInputBufferComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
	UCombatComponent* PlayerCombatComponent;
	UFUNCTION(BlueprintCallable)
	void CallLockOn();
	UFUNCTION(BlueprintCallable)
	void CallAttack();
	UFUNCTION(BlueprintCallable)
	void CallJump();
	UFUNCTION(BlueprintCallable)
	void CallDodge();
	

	virtual void SetupPlayerInputComponent(UInputComponent* Input) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/***
	*interface stuff
	***/
	UFUNCTION()
	virtual TArray<ACharacter*> GetOverlappingCharacters() override;
	UFUNCTION()
	virtual FCurrentWeaponScalingValues GetScalingInfo();
	
};
