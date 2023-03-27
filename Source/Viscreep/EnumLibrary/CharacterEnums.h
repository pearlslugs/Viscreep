#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/EnumAsByte.h"
#include "UObject/Class.h"
#include "CharacterEnums.generated.h"

/***
* Character Enums
***/

UENUM(BlueprintType)
enum class ECharacterActions : uint8
{
	ECA_None UMETA(DisplayName = "None"),
	ECA_Dodge UMETA(DisplayName = "Dodge"),
	ECA_Interact UMETA(DisplayName = "Interact"),
	ECA_Parry UMETA(DisplayName = "Parry"),
	ECA_UseItem UMETA(DisplayName = "UseItem"),
	ECA_HitReaction UMETA(DisplayName = "HitReaction"),
	ECA_EnterCombat UMETA(DisplayName = "EnterCombat"),
	ECA_ExitCombat UMETA(DisplayName = "ExitCombat"),
	ECA_SitDown UMETA(DisplayName = "SitDown"),
	ECA_GoToSleep UMETA(DisplayName = "GoToSleep"),
	ECA_StandUp UMETA(DisplayName = "StandUp"),
	ECA_AimBow UMETA(DisplayName = "AimBow"),
	ECA_CounterAttack UMETA(DisplayName = "CounterAttack"),
	ECA_GeneralAction UMETA(DisplayName = "GeneralAction")
};

UENUM(BlueprintType)
enum class ECharacterStates : uint8
{
	ECS_None UMETA(DisplayName = "None"),
	ECS_Attacking UMETA(DisplayName = "Attacking"),
	ECS_InCombat UMETA(DisplayName = "InCombat"),
	ECS_HitStunned UMETA(DisplayName = "HitStunned"),
	ECS_Stunned UMETA(DisplayName = "Stunned"),
	ECS_Interacting UMETA(DisplayName = "Interacting"),
	ECS_Dodging UMETA(DisplayName = "Dodging"),
	ECS_KnockedDown UMETA(DisplayName = "KnockedDown"),
	ECS_ComposureBroken UMETA(DisplayName = "ComposureBroken"),
	ECS_BlockStunned UMETA(DisplayName = "BlockStunned"),
	ECS_GettingUp UMETA(DisplayName = "GettingUp"),
	ECS_UsingOffHandTool UMETA(DisplayName = "UsingOffHandTool"),
	ECS_Aiming UMETA(DisplayName = "Aiming"),
	ECS_Dead UMETA(DisplayName = "Dead"),
	ECS_Disabled UMETA(DisplayName = "Disabled"),
	ECS_GeneralAction UMETA(DisplayName = "GeneralAction"),
	ECS_Parrying UMETA(DisplayName = "Parrying")
};

UENUM(BlueprintType)
enum class ECharacterInteractionState : uint8
{
	ECIS_None UMETA(DisplayName = "None"),
	ECIS_Working UMETA(DisplayName = "Working"),
	ECIS_Combat UMETA(DisplayName = "Combat"),
	ECIS_HoldingFoodItem UMETA(DisplayName = "HoldingFoodItem"),
	ECIS_UsingOffHandTool UMETA(DisplayName = "UsingOffHandTool"),
	ECIS_UsingInGameMenu UMETA(DisplayName = "UsingInGameMenu"),
};

UENUM(BlueprintType)
enum class EPersonalityTypes : uint8
{
	EPT_None UMETA(DisplayName = "None")
};

UENUM(BlueprintType)
enum class ECharacterStats : uint8
{
	ECS_Vitality UMETA(DisplayName = "Vitality"),
	ECS_Endurence UMETA(DisplayName = "Endurence"),
	ECS_Strength UMETA(DisplayName = "Strength"),
	ECS_Dextarity UMETA(DisplayName = "Dextarity"),
	ECS_Charisma UMETA(DisplayName = "Charisma"),
	ECS_Mutagenics UMETA(DisplayName = "Mutagenics"),
	ECS_Spirit UMETA(DisplayName = "Spirit"),
	ECS_Intelligence UMETA(DisplayName = "Intelligence")
};

UENUM(BlueprintType)
enum class EBleedingAmount : uint8
{
	EBA_None UMETA(DisplayName = "None"),
	EBA_Light UMETA(DisplayName = "Light"),
	EBA_Medium UMETA(DisplayName = "Medium"),
	EBA_Heavy UMETA(DisplayName = "Heavy")
};

enum class EBodyPart : uint8
{
	EBP_Head UMETA(DisplayName = "Head"),
	EBP_Neck UMETA(DisplayName = "Neck"),
	EBP_UpperBody UMETA(DisplayName = "Chest"),
	EBP_Shoulders UMETA(DisplayName = "Shoulders"),
	EBP_Arms UMETA(DisplayName = "Arms"),
	EBP_Hands UMETA(DisplayName = "Hands"),
	EBP_Legs UMETA(DisplayName = "Legs"),
	EBP_Feet UMETA(DisplayName = "Feet")
};

enum class EDefenseOptions : uint8
{
	EBP_None UMETA(DisplayName = "None"),
	EBP_BlockOnly UMETA(DisplayName = "BlockOnly"),
	EBP_DodgleOnly UMETA(DisplayName = "DodgeOnly"),
	EBP_Both UMETA(DisplayName = "Both")
};

UENUM(BlueprintType)
enum class ECharacterCusomizationOptions : uint8
{
	ECCO_None UMETA(DisplayName = "None"),	
	ECCO_Nose UMETA(DisplayName = "Nose"),
	ECCO_Eyes UMETA(DisplayName = "Eyes"),
	ECCO_Chin UMETA(DisplayName = "Chin"),
	ECCO_Cheeks UMETA(DisplayName = "Cheeks"),
	ECCO_Hair UMETA(DisplayName = "Hair"),
	ECCO_BodyType UMETA(DisplayName = "BodyType"),
	ECCO_FacialHair UMETA(DisplayName = "FacialHair"),
};