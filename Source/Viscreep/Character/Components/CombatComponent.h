// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../EnumLibrary/CombatEnums.h"
#include "../../StructLibrary/StructLibrary.h"
#include "BaseCombatComponent.h"
#include "Engine/EngineTypes.h"
#include "TimerManager.h"
#include "Delegates/Delegate.h"
#include "CombatComponent.generated.h"

// Forward Decarations
class UCameraComponent;
class APlayerCameraManager;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPositionChanged, EDefensePosition, NewPosition);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLockedOnChange, bool, CurrentlyLockedOn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIncomingAttack, EDefensePosition, TargetedPosition);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMontageRequeted, EAttackPosition, TargetedPosition, EAllAttackTypes, OutAttackType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VISCREEP_API UCombatComponent : public UBaseCombatComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();
	UFUNCTION(BlueprintCallable)
	void Initialize(ACharacter* Owner, APlayerController* PlayerController);


	// event delagates
	UPROPERTY(BlueprintAssignable)
	FOnPositionChanged OnPositionChanged;
	UPROPERTY(BlueprintAssignable)
	FOnMontageRequeted OnMontageRequeted;
	UPROPERTY(BlueprintAssignable)
	FOnLockedOnChange OnLockedOn;

	FTimerHandle LockonTimerHandler;
	float LockOnInterval = 0.025f;
	FTimerDynamicDelegate ContinueLockingOn;

	FTimerHandle PositionTimerHandle;
	float CheckPositionInterval = 0.05f;
	FTimerDynamicDelegate CheckPosition;

	

	// lockon
	void LockOn();

	// attacking
	UFUNCTION(BlueprintCallable)
	void Attack(EAllAttackTypes CurrentAttackType);
	UFUNCTION(BlueprintCallable)
	void ContinueAttacking(EAllAttackTypes CurrentAttackType);
	



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	ACharacter* CharacterOwner;
	

	

	// combat functions

	void BeginCombat();
	UFUNCTION()
	void EmitPosition();

	// lock on
	UPROPERTY(BlueprintReadOnly)
	AActor* TargetedActor;
	TArray<AActor*> PotentialTargets;
	UCameraComponent* OwnerCamera;
	APlayerCameraManager* PlayerCameraManager;
	APlayerController* PlayerController;
	bool IsTargeting;
	void SwitchTargetingCamera(bool ShouldBeEnabled);
	UFUNCTION()
	void ContinuousLockOn();
	UFUNCTION()
	void StopTargeting();
	UFUNCTION()
	bool FindClosestActor();
	void BeginTargeting();

	// protected attacks
	UFUNCTION()
	void PrimaryAttack();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
