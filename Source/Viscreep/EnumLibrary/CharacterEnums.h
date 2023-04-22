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
enum class ECombatState : uint8
{
	ECS_None UMETA(DisplayName = "None"),
	ECS_Attacking UMETA(DisplayName = "Attacking"),
	ECS_InCombat UMETA(DisplayName = "InCombat"),
	ECS_HitStunned UMETA(DisplayName = "HitStunned"),
	ECS_Stunned UMETA(DisplayName = "Stunned"),
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
	ECS_Parrying UMETA(DisplayName = "Parrying"),
	ECS_Strafing UMETA(DisplayName = "Strafing")
};

UENUM(BlueprintType)
enum class ECharacterGeneralState : uint8
{
	ECGS_None UMETA(DisplayName = "None"),
	ECGS_General UMETA(DisplayName = "General"),
	ECGS_Working UMETA(DisplayName = "Working"),
	ECGS_Combat UMETA(DisplayName = "Combat"),
	ECGS_HoldingFoodItem UMETA(DisplayName = "HoldingFoodItem"),
	ECGS_UsingOffHandTool UMETA(DisplayName = "UsingOffHandTool"),
	ECGS_UsingInGameMenu UMETA(DisplayName = "UsingInGameMenu"),
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

UENUM(BlueprintType)
enum class EWellbeingStats : uint8
{
	EWS_OverallHealth UMETA(DisplayName = "OverallHealth"),
	EWS_PainLevel UMETA(DisplayName = "OverallHealth"),
	EWS_Composure UMETA(DisplayName = "OverallHealth"),
	EWS_MentalHealth UMETA(DisplayName = "OverallHealth"),
};

UENUM(BlueprintType)
enum class EBodyPart : uint8
{
	EBP_Head UMETA(DisplayName = "Head"),
	EBP_Neck UMETA(DisplayName = "Neck"),
	EBP_Torso UMETA(DisplayName = "Torso"),
	EBP_LeftArm UMETA(DisplayName = "LeftArm"),
	EBP_RightArm UMETA(DisplayName = "RightArm"),
	EBP_Hands UMETA(DisplayName = "Hands"),
	EBP_LeftLeg UMETA(DisplayName = "LeftLeg"),
	EBP_RightLeg UMETA(DisplayName = "RightLeg"),
	EBP_Feet UMETA(DisplayName = "Feet")
};

UENUM(BlueprintType)
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

UENUM(BlueprintType)
enum class EHostilityTeam : uint8
{
	EHT_None UMETA(DisplayName = "None"),
	EHT_PlayerCharacter UMETA(DisplayName = "PlayerCharacter"),
	EHT_Feral UMETA(DisplayName = "Feral"),
	EHT_HostileDueToFaction UMETA(DisplayName = "HostileDueToFaction"),
	EHT_HostileDueToCrime UMETA(DisplayName = "HostileDueToCrime"),
	EHT_HostileDueToAnger UMETA(DisplayName = "HostileDueToAnger"),
	EHT_AllyInCombat UMETA(DisplayName = "AllyInCombat"),
	EHT_NotHostile UMETA(DisplayName = "NotHostile"),
};