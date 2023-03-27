// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseRPGCharacter.h"
#include "PlayerCharacter.generated.h"

 /********************
 *    Declarations   *
 *					 *
 *********************/

class UInputBufferComponent;
class UCombatComponent;

UCLASS()
class VISCREEP_API APlayerCharacter : public ABaseRPGCharacter
{
	GENERATED_BODY()
	APlayerCharacter();

public:
	UInputBufferComponent* PlayerInputBufferComponent;
	UCombatComponent* PlayerCombatComponent;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
