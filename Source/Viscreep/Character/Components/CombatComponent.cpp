// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "../Player/PlayerCharacterInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// initialize lock on timer
	ContinueLockingOn.BindDynamic(this, &UCombatComponent::ContinuousLockOn);

	// initialize timer to emit position
	
	CheckPosition.BindDynamic(this, &UCombatComponent::EmitPosition);
	IsTargeting = false;
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();


	//GetWorld()->GetTimerManager().SetTimer(LockonTimerHandler, ContinueLockingOn, CheckPositionInterval, true);
	//UCombatComponent::BeginCombat();

	// ...
	
}

void UCombatComponent::Initialize(ACharacter* InOwner, APlayerController* InPlayerController)
{
	if (IsValid(InOwner) && IsValid(InPlayerController))
	{
		PlayerController = InPlayerController;
		PlayerCameraManager = PlayerController->PlayerCameraManager;
		CharacterOwner = InOwner;
	}
}


// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool UCombatComponent::FindClosestActor()
{
	FVector OwnerLocation = CharacterOwner->GetActorLocation();
	FVector PotentialTargetLocation;
	float ClosestTargetDistance = 99000.f;
	AActor* CurrentClosestActor = nullptr;
	for (auto Target : PotentialTargets)
	{
		PotentialTargetLocation = Target->GetActorLocation();

		if ((PotentialTargetLocation - PotentialTargetLocation).Length() < ClosestTargetDistance)
		{
			CurrentClosestActor = Target;
		}
	}
	if (CurrentClosestActor)
	{
		TargetedActor = CurrentClosestActor;
		return true;
	}
	return false;
}

void UCombatComponent::LockOn()
{
	// look at Targeted Actor
	// lock on
	if (IsTargeting)
	{
		UCombatComponent::StopTargeting();
	}
	else
	{
		if (PotentialTargets.Num() > 0)
		{

			if (UCombatComponent::FindClosestActor())
			{
				UCombatComponent::BeginTargeting();
			}
			else {
				// oops
				//UCombatComponent::StopTargeting();
			}
		}
		else
		{
			IPlayerCharacterInterface* InterfaceOwner = Cast<IPlayerCharacterInterface>(CharacterOwner);
			if (InterfaceOwner)
			{
				PotentialTargets.Append(InterfaceOwner->GetOverlappingCharacters());
				if (PotentialTargets.Num() > 0)
				{
					if (UCombatComponent::FindClosestActor())
					{
						UCombatComponent::BeginTargeting();
					}
					else
					{
						//UCombatComponent::StopTargeting();
					}
				}
			}
		}
	}
}

void UCombatComponent::BeginCombat()
{

	CurrentAttackPosition = EAttackPosition::EAP_AttackMid;
	CurrentDefensePosition = EDefensePosition::EDP_AttackMid;
	PreviousDefensePosition = EDefensePosition::EDP_AttackMid;
	//UCombatComponent::LockOn();
	
	GetWorld()->GetTimerManager().SetTimer(PositionTimerHandle, CheckPosition, CheckPositionInterval, true);
}

void UCombatComponent::EmitPosition()
{
	if (CurrentDefensePosition != PreviousDefensePosition)
	{
		SetCurrentAttackPosition(DefensePositionToAttackPosition(CurrentDefensePosition));
		PreviousDefensePosition = CurrentDefensePosition;
		OnPositionChanged.Broadcast(CurrentDefensePosition);
	}

}

void UCombatComponent::ContinuousLockOn()
{
	if (PlayerController && IsValid(TargetedActor) && (GetOwner()->GetActorLocation() - TargetedActor->GetActorLocation()).Size() > 100.f)
	{
		FVector CameraLocation = PlayerCameraManager->GetCameraLocation();
		FVector CameraForward = PlayerCameraManager->GetCameraRotation().Vector();
		FRotator CurrentCameraRotation = PlayerController->GetControlRotation();
		FRotator DesiredRotation = UKismetMathLibrary::FindLookAtRotation(CameraLocation, TargetedActor->GetActorLocation());
		UKismetMathLibrary::RInterpTo(CurrentCameraRotation, DesiredRotation, 0.025f, 8);
		FRotator NewRotator = FRotator(FMath::Clamp(DesiredRotation.Pitch, -25, 30), DesiredRotation.Yaw, CurrentCameraRotation.Roll);
		PlayerController->SetControlRotation(NewRotator);
	}
	else
	{
	
	}
}

void UCombatComponent::SwitchTargetingCamera(bool ShouldBeEnabled)
{
	if (CharacterOwner)
	{
		if (ShouldBeEnabled)
		{
			
		}
		else 
		{
			CharacterOwner->bUseControllerRotationYaw = false;
		}
	}
}

void UCombatComponent::BeginTargeting()
{
	IsTargeting = true;
	OnLockedOn.Broadcast(true);
	BeginCombat();
	GetWorld()->GetTimerManager().SetTimer(LockonTimerHandler, ContinueLockingOn, LockOnInterval, true);
}

void UCombatComponent::StopTargeting()
{
	if (IsTargeting)
	{
		IsTargeting = false;
		//updates the UI
		OnLockedOn.Broadcast(false);
		TargetedActor = nullptr;
		GetWorld()->GetTimerManager().PauseTimer(LockonTimerHandler);
	}
}

// attacking
void UCombatComponent::Attack(EAllAttackTypes CurrentAttackType)
{
	OnMontageRequeted.Broadcast(CurrentAttackPosition, CurrentAttackType);
}
void UCombatComponent::ContinueAttacking(EAllAttackTypes CurrentAttackType)
{
	switch (CurrentAttackType)
	{
	case EAllAttackTypes::EAAT_Primary:
		UCombatComponent::PrimaryAttack();
		break;
	}
}
void UCombatComponent::PrimaryAttack()
{
	
}

