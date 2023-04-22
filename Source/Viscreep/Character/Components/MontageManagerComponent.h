// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../StructLibrary/StructLibrary.h"
#include "../../EnumLibrary/CombatEnums.h"
#include "../../EnumLibrary/HitReactionEnums.h"
#include "MontageManagerComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VISCREEP_API UMontageManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMontageManagerComponent();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int AttackCount;

	// All Montages "db"
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap <EAllWeaponStanceTypes, FWeaponDependantMontages> AllWeaponMontages;

	UFUNCTION(BlueprintCallable)
	void InitializeAllWeaponMontages(TMap <EAllWeaponStanceTypes, FWeaponDependantMontages> InMap);
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap <ECharacterActions, FGeneralAnimMontageStructArray> GeneralActionMontages;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FWeaponDependantMontages CurrentWeaponMontages;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<EMeleeSwingDirection, FDirectionalMontageStructArrays> CurrentHitReactionMontages;
	UFUNCTION(BlueprintCallable)
	void UpdateCurrentWeaponMontages(EAllWeaponStanceTypes CurrentWeapon);
	UFUNCTION(BlueprintCallable)
		FWeaponDependantMontages GetMontages()
	{
		return CurrentWeaponMontages;
	}
protected:
	virtual void BeginPlay() override;
	void KeepAttackCountInBounds(TArray<FAnimMontageStruct> CurrentAttackTypeMontages);

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	FAnimMontageStruct GetCurrentMontage(EAllAttackTypes InAttackType, EAttackPosition CurrentAttackPosition);
	UFUNCTION(BlueprintCallable)
		TArray<FAnimMontageStruct> GetHitreactionMontgeArray(EAttackPosition InPosition, EMeleeSwingDirection CurrentDirection);
	UFUNCTION(BlueprintCallable)
		void UpdateHitReactionMontages(TMap<EMeleeSwingDirection, FDirectionalMontageStructArrays> InMontages)
	{
		CurrentHitReactionMontages = InMontages;
	}
};
