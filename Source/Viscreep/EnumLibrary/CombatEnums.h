#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/EnumAsByte.h"
#include "UObject/Class.h"
#include "CombatEnums.generated.h"

UENUM(BlueprintType)
enum class EAttackPosition : uint8 
{
	EAP_None UMETA(DisplayName = "None"),
	EAP_AttackHigh UMETA(DisplayName = "AttackHigh"),
	EAP_AttackMid UMETA(DisplayName = "AttackMid"),
	EAP_AttackLow UMETA(DisplayName = "AttackLow"),
	EAP_KickLow UMETA(DisplayName = "KickLow"),
	EAP_KickHigh UMETA(DisplayName = "KickHigh"),
	EAP_Shove UMETA(DisplayName = "Shove")
};

UENUM(BlueprintType)
enum class EDefensePosition : uint8
{
	EDP_None UMETA(DisplayName = "None"),
	EDP_AttackHigh UMETA(DisplayName = "High"),
	EDP_AttackMid UMETA(DisplayName = "Mid"),
	EDP_AttackLow UMETA(DisplayName = "Low")
};

UENUM(BlueprintType)
enum class EGeneralDamageType : uint8
{
	EGDT_None UMETA(DisplayName = "None"),
	EGDT_Physical UMETA(DisplayName = "Physical"),
	EGDT_Elemental UMETA(DisplayName = "Elemental"),
	EGDT_Both UMETA(DisplayName = "Both"),
	EGDT_Composure UMETA(DisplayName = "Composure")
};

UENUM(BlueprintType)
enum class EPhysicalDamageType : uint8
{
	EPDT_None UMETA(DisplayName = "None"),
	EPDT_Blunt UMETA(DisplayName = "Blunt"),
	EPDT_Hack UMETA(DisplayName = "Hack"),
	EPDT_Slash UMETA(DisplayName = "slash"),
	EPDT_Pierce UMETA(DisplayName = "Pierce"),
	EPDT_Composure  UMETA(DisplayName = "Composure")
};

UENUM(BlueprintType)
enum class EElementalDamageType : uint8
{
	EEDT_None UMETA(DisplayName = "None"),
	EEDT_Fire UMETA(DisplayName = "Fire"),
	EEDT_Dark UMETA(DisplayName = "Dark"),
	EEDT_Lightning UMETA(DisplayName = "Lightning")
};

UENUM(BlueprintType)
enum class EMeleeSwingDirection : uint8
{
	EMSD_None UMETA(DisplayName = "None"),
	EMSD_Default UMETA(DisplayName = "Default"),
	EMSD_HorizontalLeft UMETA(DisplayName = "HorizontalLeft"),
	EMSD_HorizontalRight UMETA(DisplayName = "HorizontalRight"),
	EMSD_VerticalDown UMETA(DisplayName = "VerticalDown"),
	EMSD_VerticalUp UMETA(DisplayName = "VerticalUp"),
	EMSD_ForwardThrust UMETA(DisplayName = "ForwardThrust"),
};

UENUM(BlueprintType)
enum class ECurrentDamageTypeForTrace : uint8
{
	ECDT_None UMETA(DisplayName = "None"),
	ECDT_Primary UMETA(DisplayName = "Primary"),
	ECDT_Secondary UMETA(DisplayName = "Secondary"),
	ECDT_tertiary UMETA(DisplayName = "Secondary"),
};

UENUM(BlueprintType)
enum class EAllAttackTypes : uint8
{
	
	EAAT_None UMETA(DisplayName = "None"), 
	EAAT_Primary UMETA(DisplayName = "Primary"), 
	EAAT_Secondary UMETA(DisplayName = "Secondary"), 
	EAAT_Tertiary UMETA(DisplayNAme = "Tertiary"),
	EAAT_Slam UMETA(DisplayName = "Slam"), 
	EAAT_Precise UMETA(DisplayName = "Precise"), 
	EAAT_Kick UMETA(DisplayName = "Kick"), 
	EAAT_Shove UMETA(DisplayName = "Shove"), 
	EAAT_WeaponBash UMETA(DisplayName = "WeaponBash"),
	EAAT_Critical UMETA(DisplayName = "Critical"),
	EAAT_Counter UMETA(DisplayName = "Counter"),
	EAAT_ShootWeapon UMETA(DisplayName = "ShootWeapon"),
	EAAT_Grab UMETA(DisplayName = "Grab"),
	EAAT_Struggle UMETA(DisplayName = "Struggle"),
};

UENUM(BlueprintType)
enum class EAllWeaponStanceTypes : uint8
{
	EAWST_None UMETA(DisplayName = "None"),
	EAWST_OneHandedSword UMETA(DisplayName = "OneHandedSword"),
	EAWST_OneHandedAxeOrMace UMETA(DisplayName = "OneHandedAxeOrMace"),
	EAWST_OneHandedThrustingSword UMETA(DisplayName = "OneHandedThrustingSword"),
	EAWST_TwoHandedBaseGrip UMETA(DisplayName = "TwoHandedBaseGrip"),
	EAWST_TwoHandedPoleGripSlash UMETA(DisplayName = "TwoHandedPoleGripSlash"),
	EAWST_TwoHandedPoleGripStab UMETA(DisplayName = "TwoHandedPoleGripStab"),
};

UENUM(BlueprintType)
enum class EDamageInflictionAmount : uint8
{
	EDIA_None UMETA(DisplayName = "None"),
	EDIA_Extreme UMETA(DisplayName = "Extreme"),
	EDIA_Heavy UMETA(DisplayName = "Heavy"),
	EDIA_Mid UMETA(DisplayName = "Mid"),
	EDIA_MidLight UMETA(DisplayName = "MidLight"),
	EDIA_Light UMETA(DisplayName = "Light"),
	EDIA_Glancing UMETA(DisplayName = "Glancing"),
};

