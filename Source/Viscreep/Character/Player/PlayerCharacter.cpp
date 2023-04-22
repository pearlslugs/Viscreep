// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "../Components/InputBufferComponent.h"
#include "../Components/MontageManagerComponent.h"
#include "EnhancedInputComponent.h"
#include "../Components/BaseStatsComponent.h"
#include "../../Items/Weapon/AttackLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "../Components/CombatComponent.h"



APlayerCharacter::APlayerCharacter()
{
	
	PlayerInputBufferComponent = CreateDefaultSubobject<UInputBufferComponent>(TEXT("PlayerInputBufferComponent"));
	PlayerCombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("PlayerCombatComponent"));

}
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* Input)
{
	Super::SetupPlayerInputComponent(Input);
	auto* EnhancedInput{ Cast<UEnhancedInputComponent>(Input) };
	
	EnhancedInput->BindAction(LockOnAction, ETriggerEvent::Triggered, this, &APlayerCharacter::CallLockOn);
	EnhancedInput->BindAction(PrimaryAttackAction, ETriggerEvent::Triggered, this, &APlayerCharacter::CallAttack);
	EnhancedInput->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::CallJump);
	EnhancedInput->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &ThisClass::CallDodge);
}

void APlayerCharacter::CallLockOn()
{
	PlayerCombatComponent->LockOn();
}

// Called when the game starts
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ...
}

TArray<ACharacter*> APlayerCharacter::GetOverlappingCharacters()
{
	TArray<ACharacter*> HitCharacters;
	TArray<FHitResult> HitResults;
	FCollisionShape BoxTracer = FCollisionShape::MakeBox(FVector(2500, 2500, 500));
	GetWorld()->SweepMultiByChannel(HitResults, GetActorLocation(), GetActorLocation() + FVector(0.f, 0.f, 10.f), FQuat::Identity, ECC_Pawn, BoxTracer);
	for (auto HitResult : HitResults)
	{
		ACharacter* HitCharacter = Cast<ACharacter>(HitResult.GetActor());
			if (HitCharacter && HitCharacter != this)
			{
				HitCharacters.Add(HitCharacter);
		}
	}
	
	return HitCharacters;
}

FCurrentWeaponScalingValues APlayerCharacter::GetScalingInfo()
{
	FCurrentWeaponScalingValues CurrentScaling = CharacterStatsComponent->CurrentWeaponScalingValues;
	return CurrentScaling;
}

void APlayerCharacter::CallAttack()
{
	//if character state does not equal anything that would forbid this action
	PlayerInputBufferComponent->AcceptKey(EBufferKey::EBK_PrimaryAttack);
}

void APlayerCharacter::CallJump()
{
	PlayerInputBufferComponent->AcceptKey(EBufferKey::EBK_Jump);
}

void APlayerCharacter::CallDodge()
{
	PlayerInputBufferComponent->AcceptKey(EBufferKey::EBK_Dodge);
}