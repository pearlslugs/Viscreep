// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../EnumLibrary/CharacterEnums.h"
#include "../../Items/Weapon/WeaponBase.h"
#include "../../StructLibrary/StructLibrary.h"
#include "../../Items/Weapon/AttackLibrary.h"
#include "Curves/CurveFloat.h"
#include "Containers/Map.h"

#include "BaseStatsComponent.generated.h"



class AWeaponBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VISCREEP_API UBaseStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	FTimerHandle BleedingTimer;
	float BleedingInterval = 3.f;
	FTimerDynamicDelegate ContinueBleeding;
	bool Isbleeding;

	FActorHitSignature ActorHitSignature;
	UBaseStatsComponent();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCurveFloat* DexterityCurve;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCurveFloat* StrengthCurve;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<ECharacterStats, float> StatsMap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EBodyPart, FBodyPartStruct> BodyPartsMap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FWeaponData StatsWeaponData;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FCurrentWeaponScalingValues CurrentWeaponScalingValues;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EWellbeingStats, float> CharacterWellbeingMap;
	UFUNCTION()
	void MakeDamageValuesFromAttack(float AmountOfDamage, EPhysicalDamageType InDamageType);
	
	void DamageWellbeingStat(TArray<FDamageWellbeingStruct> DamageValues);

	UFUNCTION(BlueprintCallable)
	void OnMeleeHit(AActor* HitActor, FHitTraceResults HitResults);
	UFUNCTION(blueprintCallable)
	void InitializeWeaponData(AWeaponBase* InWeapon, FWeaponData InWeaponData, float DamageValue);
	
	FOutgoingAttackStruct CurrentAttackInfo;
	UFUNCTION(BlueprintCallable)
	void StoreCurrentAttackInfo(FOutgoingAttackStruct InProgressAttack)
	{
		CurrentAttackInfo = InProgressAttack;
	}
	UFUNCTION()
	void UpdateBodyPart(FBodyPartStruct InBodyPart)
	{
		BodyPartsMap.Add(InBodyPart.BodyPart, InBodyPart);
	}

	void CheckForBleeding();

	UFUNCTION(BlueprintCallable)
	FOutgoingAttackStruct MakeOutgoingAttack();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void InitializeStats();
	void GetWeaponDamageForAttack();
	
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
