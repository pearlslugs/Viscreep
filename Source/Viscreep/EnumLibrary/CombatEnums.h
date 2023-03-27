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
	EPDT_Pierce UMETA(DisplayName = "Pierce")
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
enum class ECurrentDamageType : uint8
{
	ECDT_None UMETA(DisplayName = "None"),
	ECDT_Primary UMETA(DisplayName = "Primary"),
	ECDT_Secondary UMETA(DisplayName = "Secondary"),
	ECDT_tertiary UMETA(DisplayName = "Secondary"),
};