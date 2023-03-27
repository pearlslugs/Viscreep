#pragma once

#include "CoreMinimal.h"
#include "../EnumLibrary/CombatEnums.h"
#include "../EnumLibrary/CharacterEnums.h"
#include "../EnumLibrary/EnumLibrary.h"
#include "../EnumLibrary/HitReactionEnums.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "../Items/DataAssets/GeneralItem.h"
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
struct FOutgoingAttackStruct
{
	GENERATED_BODY()

	EAttackPosition CurrentAttackPosition;

	EGeneralDamageType AttackDamageType;
	EPhysicalDamageType AttackPhysicalDamageType;
	EElementalDamageType AttackElementalDamageType;

	float Velocity;
	float Precision;

	float ComposureDamage;
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
	EPhysicalDamageType PrimaryDamageType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EPhysicalDamageType SecondaryDamageType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EPhysicalDamageType tertiaryDamageType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EPhysicalDamageType, float> DamageAmountMap;
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

	UAnimMontage* MontageToPlay;
	float PlayRate;
	float InTimeToStartMontageAt;
	float ResetTimeMultiplier;

};

USTRUCT(BlueprintType)
struct FGeneralAnimMontageStructArray
{
	GENERATED_BODY()

	TArray<FAnimMontageStruct> Montages;
	TArray<FAnimMontageStruct> AlternativeMontages;
};

USTRUCT(BlueprintType)
struct FDirectionalMontageStructArrays
{
	GENERATED_BODY()

	TArray<FAnimMontageStruct> LowMontages;
	TArray<FAnimMontageStruct> MidMontages;
	TArray<FAnimMontageStruct> HighMontages;
	TArray<FAnimMontageStruct> AlternativeLowMontages;
	TArray<FAnimMontageStruct> AlternativeMidMontages;
	TArray<FAnimMontageStruct> AlternativeHighMontages;
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
	UGeneralItem* ContainedDataAsset;
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