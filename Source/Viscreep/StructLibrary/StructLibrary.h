#pragma once

#include "CoreMinimal.h"
#include "../EnumLibrary/CombatEnums.h"
#include "../EnumLibrary/CharacterEnums.h"
#include "../EnumLibrary/EnumLibrary.h"
#include "../EnumLibrary/HitReactionEnums.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/EnumAsByte.h"
#include "UObject/Class.h"
#include "Animation/AnimMontage.h"
#include "Math/TransformNonVectorized.h"
#include "Math/Vector.h"
#include "StructLibrary.generated.h"

/***
* Combat Structs
***/

USTRUCT(BlueprintType)
struct FAttackTraceStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMeleeSwingDirection SwingDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAttackPosition AttackPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAllAttackTypes AttackTypeToUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECustomAttackTypes CustomAttackType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Multiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Blockable;
};

USTRUCT(BlueprintType)
struct FOutgoingAttackStruct
{
	GENERATED_BODY()

	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	EAttackPosition CurrentAttackPosition;

	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	EGeneralDamageType AttackDamageType;
	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	EPhysicalDamageType AttackPhysicalDamageType;
	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	EElementalDamageType AttackElementalDamageType;

	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	float Velocity;
	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	float Precision;

	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	FAttackTraceStruct TraceInfo;

	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	float ComposureDamage;

	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	FName HitBoneName;
	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	FVector HitLocation;
};


USTRUCT(BlueprintType)
struct FRecievedAttackStruct
{
	GENERATED_BODY()


	EBodyPart CurrentBodyPartToDamage;
	EBleedingAmount AmountOfBleedingToAddToLimb;
	
	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	float DamageToComposure;
	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	float PainToCause;
	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	float DamageToArmor;
	UPROPERTY(Category = "OutGoingAttack", EditAnywhere, BlueprintReadWrite)
	float DamageToLimb;
};

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EPhysicalDamageType PrimaryDamageType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EPhysicalDamageType SecondaryDamageType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EPhysicalDamageType tertiaryDamageType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<ECharacterStats, float> StatsScalingMap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EPhysicalDamageType, float> DamageTypeMap;
};

USTRUCT(BlueprintType)
struct FArmorData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EPhysicalDamageType, float> DamageResistanceAmounts;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EArmorClass ArmorClass;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CurrentHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsDestroyed = false;;
	void DamageHealth(float InDamage)
	{
		if(CurrentHealth > 0)
		{
			CurrentHealth = CurrentHealth - InDamage;
			if (CurrentHealth < 0)
			{
				IsDestroyed = true;
			}
		}
		else
		{
			IsDestroyed = true;
		}
	}

};

USTRUCT(BlueprintType)
struct FItemPropertiesStruct
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMaterialType ItemMaterial;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FWeaponData CurrentWeaponData;
	//armor data


};
/***
* Animation Structs
***/
USTRUCT(BlueprintType)
struct FAnimMontageStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	UAnimMontage* MontageToPlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	float PlayRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	float InTimeToStartMontageAt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	float ResetTimeMultiplier;

};

USTRUCT(BlueprintType)
struct FGeneralAnimMontageStructArray
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TArray<FAnimMontageStruct> Montages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TArray<FAnimMontageStruct> AlternativeMontages;
};

USTRUCT(BlueprintType)
struct FDirectionalMontageStructArrays
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TArray<FAnimMontageStruct> LowMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TArray<FAnimMontageStruct> MidMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TArray<FAnimMontageStruct> HighMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TArray<FAnimMontageStruct> AlternativeLowMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TArray<FAnimMontageStruct> AlternativeMidMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TArray<FAnimMontageStruct> AlternativeHighMontages;
};

USTRUCT(BlueprintType)
struct F2DDirectionalMontageStructArrays
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TMap<EMeleeSwingDirection, FDirectionalMontageStructArrays> LowMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TMap<EMeleeSwingDirection, FDirectionalMontageStructArrays> MidMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TMap<EMeleeSwingDirection, FDirectionalMontageStructArrays> HighMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TMap<EMeleeSwingDirection, FDirectionalMontageStructArrays> AlternativeLowMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TMap<EMeleeSwingDirection, FDirectionalMontageStructArrays> AlternativeMidMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	TMap<EMeleeSwingDirection, FDirectionalMontageStructArrays> AlternativeHighMontages;
};


USTRUCT(BlueprintType)
struct FAmmoInfoStruct
{
	GENERATED_BODY()

	UStaticMesh* AmmoMesh;
	ECurrentAmmoType AmmoType;
	UClass* AmmoClass;

};

USTRUCT(BlueprintType)
struct FRangedWeaponInfoStruct
{
	GENERATED_BODY()

	float FireSpeed;
	EEquipSocketOption EquipSocket;
	EUnequipSocketOption UnEquipSocket;
	FName PlayerHandSocketName;

};

USTRUCT(BlueprintType)
struct FAttackTypeTrackingStruct
{
	GENERATED_BODY()

	EAttackPosition CountedAttackPosition;
	int NumberOfAttacksInThisPosition;
	/***
	* TODO
	* needs more info, light and
	* strong attacks should be
	* counted differently, as
	* well ass attacks with different
	* weapons
	***/

};

USTRUCT(BlueprintType)
struct FCombatHitDataStruct
{
	GENERATED_BODY()

	AActor* HitActor;
	AActor* DamageCauser;
	float HitYawAngle;
	float HitDistance;
	bool CanBeBlocked;
	bool CanBeParried;
	FVector ImpactLocation;
	FVector ImpactDirection;
	FName HitBone;
	EHitFacingDirection HitDirection;
	EImpactDecision ImpactDecision;
	FOutgoingAttackStruct IncomingAttackInfo;
};

USTRUCT(BlueprintType)
struct FSlotItemStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Asset")
	UDataAsset* ContainedDataAsset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryType")
	EInventoryType InventoryType;
};

USTRUCT(BlueprintType)
struct FCharacterInfoStruct
{
	GENERATED_BODY()
	ECharacterCusomizationOptions CharacterCustomization;
	TMap<ECharacterStats, int> CharacterStats;
	TMap<EEquipmentSlot, int> CharacterEquippedItems;
};


/***
* Save Objects
***/

USTRUCT(BlueprintType)
struct FCharacterSaveInfoStruct
{
	GENERATED_BODY()

	//CharacterInfoStruct?
	//Equipped Items
	FTransform* CurrentTransform;
	//BodyPartsMap
	//StatsMap
	//HealthInfo
	//History
	//Personality
	//Moodlets
	//LongTermMood
};

USTRUCT(BlueprintType)
struct FDamageBodyPartStruct
{
	GENERATED_BODY()
		float AmountOfDamage;
	EPhysicalDamageType PhysicalDamageType;
	void InitializeDamageStruct(float InAmountToDamage, EPhysicalDamageType InTypeOfDamage)
	{
		AmountOfDamage = InAmountToDamage;
		PhysicalDamageType = InTypeOfDamage;
	}
};

USTRUCT(BlueprintType)
struct FBodyPartStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBodyPart BodyPart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FArmorData ArmorBodyPart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBleedingAmount BleedingAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsBroken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsMissing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsMutated;

	void CauseBleeding(uint8 AmountOFBleedingToAdd)
	{
		uint8 BleedingAsByte = (uint8)BleedingAmount;
		if (BleedingAsByte + AmountOFBleedingToAdd < 3)
		{
			BleedingAsByte = BleedingAsByte + AmountOFBleedingToAdd;
		}
		else
		{
			BleedingAsByte = 3;
		}
		switch (BleedingAsByte)
		{
		case 0:
			BleedingAmount = EBleedingAmount::EBA_None;
			break;
		case 1:
			BleedingAmount = EBleedingAmount::EBA_Light;
			break;
		case 2:
			BleedingAmount = EBleedingAmount::EBA_Medium;
			break;
		case 3:
			BleedingAmount = EBleedingAmount::EBA_Heavy;
			break;
		}
	}

	void RecieveDamage(FDamageBodyPartStruct InDamage)
	{
		Health = Health - InDamage.AmountOfDamage;
		if (InDamage.PhysicalDamageType != EPhysicalDamageType::EPDT_Blunt)
		{
			if (InDamage.AmountOfDamage > 25)
			{
				CauseBleeding(2);
			}
			else 
			{
				CauseBleeding(1);
			}
		}
	}
	//EMutation Mutation
};

USTRUCT(BlueprintType)
struct FWeaponDependantMontages
{
	GENERATED_BODY()
	bool ShouldOverrideGeneeralActions = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	TMap <ECharacterActions, FGeneralAnimMontageStructArray> OverrideGeneralActions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacks")
	TMap <EAllAttackTypes, FDirectionalMontageStructArrays> AttackMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dodges")
	TMap <EDodgeDirections, FGeneralAnimMontageStructArray> DodgeMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitReactions")
	TMap <EHitReactionType, FDirectionalMontageStructArrays> HitREactionMontages;
};

USTRUCT(BlueprintType)
struct FHitTraceResults
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	FName HitBone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	FVector HitLocation;
};



USTRUCT(BlueprintType)
struct FAttackRecievedStruct
{
	GENERATED_BODY()
	FDamageBodyPartStruct DamageBodyPartStruct;
	FArmorData DamagedArmor;
	void Initialize(FDamageBodyPartStruct InDamageBodyPartStruct, FArmorData InDamagedArmor)
	{
		DamageBodyPartStruct = InDamageBodyPartStruct;
		DamagedArmor = InDamagedArmor;
	}
};

USTRUCT(BlueprintType)
struct FDamageWellbeingStruct
{
	GENERATED_BODY()
	EWellbeingStats WellbeingStatToDamage;
	float AmountOfDamage;
};