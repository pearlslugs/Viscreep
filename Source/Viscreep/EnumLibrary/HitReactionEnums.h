#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/EnumAsByte.h"
#include "UObject/Class.h"
#include "HitReactionEnums.generated.h"

UENUM(BlueprintType)
enum class EHitReactionTypes : uint8
{
	EHRT_None UMETA(DisplayName = "None"),
	EHRT_BlockReact UMETA(DisplayName = "BlockReact"),
	EHRT_HitStone UMETA(DisplayName = "HitStun"),
	EHRT_KnockOver UMETA(DisplayName = "KnockOver"),
	EHRT_Procedural UMETA(DisplayName = "Procedural")
};


UENUM(BlueprintType)
enum class ECustomAttackTypes : uint8
{
	ECAT_None UMETA(DisplayName = "None"),
	ECAT_Slam UMETA(DisplayName = "Slam"),
	ECAT_KnockInToTheAir UMETA(DisplayName = "KnickInToTheAir"),
	ECAT_KnockDown UMETA(DisplayName = "KnockDown"),
	ECAT_ProjectileBoneHitReaction UMETA(DisplayName = "ProjectileBoneHitReaction"),
	ECAT_DefenseBreakAttack UMETA(DisplayName = "DefenseBreakAttack"),
	ECAT_KnockDownAttack UMETA(DisplayName = "KnockDownAttack"),
	ECAT_GrabAttack UMETA(DisplayName = "GrabAttack"),
	ECAT_StandOffAttack UMETA(DisplayName = "StandOffAttack")
};

UENUM(BlueprintType)
enum class EDodgeDirections : uint8
{
	EDD_None UMETA(DisplayName = "None"),
	EDD_Forwards UMETA(DisplayName = "Forwards"),
	EDD_Right UMETA(DisplayName = "Right"),
	EDD_Left UMETA(DisplayName = "Left"),
	EDD_Backwards UMETA(DisplayName = "Backwards"),
	EDD_BackLeft UMETA(DisplayName = "BackLeft"),
	EDD_BackRight UMETA(DisplayName = "BackRight"),
	EDD_FrontLeft UMETA(DisplayName = "FrontLeft"),
	EDD_FrontRight UMETA(DisplayName = "FrontRight"),
	EDD_BackStep UMETA(DisplayName = "BackStep")
};

UENUM(BlueprintType)
enum class EGeneralCombatType : uint8
{
	EGCT_None UMETA(DisplayName = "None"),
	EGCT_Melee UMETA(DisplayName = "Melee"),
	EGCT_Ranged UMETA(DisplayName = "Ranged"),
	EGCT_OffHandTool UMETA(DisplayName = "OffHandTool")
};

UENUM(BlueprintType)
enum class EHitFacingDirection : uint8
{
	EHFD_None UMETA(DisplayName = "None"),
	EHFD_Front UMETA(DisplayName = "Front"),
	EHFD_Back UMETA(DisplayName = "Back"),
	EHFD_Right UMETA(DisplayName = "Right"),
	EHFD_Left UMETA(DisplayName = "Left")
};

UENUM(BlueprintType)
enum class EHitReactionIndexType : uint8
{
	EHRIT_None UMETA(DisplayName = "None"),
	EHRIT_CustomIndex UMETA(DisplayName = "CustomIndex"),
	EHRIT_RandomIndex UMETA(DisplayName = "RandomIndex"),
	EHRIT_AttackPowerIndex UMETA(DisplayName = "AttackPowerIndex")
};

UENUM(BlueprintType)
enum class EHitReactionBreakAttackDescision : uint8
{
	EHRBAD_Instant UMETA(DisplayName = "Instant"),
	EHRBAD_Buffered UMETA(DisplayName = "Buffered")
};

UENUM(BlueprintType)
enum class EHitReactionBreakAttackType : uint8
{
	EHRBAT_Attack UMETA(DisplayName = "Attack"),
	EHRBAT_Block UMETA(DisplayName = "Block"),
	EHRBAT_Dodge UMETA(DisplayName = "Dodge")
};

UENUM(BlueprintType)
enum class EHitReactionType : uint8
{
	EHRT_None UMETA(DisplayName = "None"),
	EHRT_HitStun UMETA(DisplayName = "HitStun"),
	EHRT_Parried UMETA(DisplayName = "Parried"),
	EHRT_RecoilReaction UMETA(DisplayName = "RecoilReaction"),
	EHRT_Countered UMETA(DisplayName = "Countered"),
	EHRT_HitBone UMETA(DisplayName = "HitBone"),
	EHRT_Stunned UMETA(DisplayName = "Stunned"),
	EHRT_Execution UMETA(DisplayName = "Execution"),
	EHRT_Assassinated UMETA(DisplayName = "Assassinated"),
	EHRT_BlockReaction UMETA(DisplayName = "BlockReaction"),
	EHRT_ParryReaction UMETA(DisplayName = "ParryReaction"),
	EHRT_ComposureBreaking UMETA(DisplayName = "ComposureBreaking"),
	EHRT_ComposureBroken UMETA(DisplayName = "ComposureBroken"),
	EHRT_Death UMETA(DisplayName = "Death"),
	EHRT_ReposteReaction UMETA(DisplayName = "ReposteReaction"),
	EHRT_BackStab UMETA(DisplayName = "BackStab"),
	EHRT_IKHitReaction UMETA(DisplayName = "IKHitReaction"),
	EHRT_GoFlying UMETA(DisplayName = "GoFlying")
};

UENUM(BlueprintType)
enum class EHitStunDecision : uint8
{
	EHSD_None UMETA(DisplayName = "None"),
	EHSD_Custom UMETA(DisplayName = "Custom"),
	EHSD_IKHitReaction UMETA(DisplayName = "IKHitReaction"),
	EHSD_HitStun UMETA(DisplayName = "HitStun"),
};

UENUM(BlueprintType)
enum class EImpactDecision : uint8
{
	EID_None UMETA(DisplayName = "None"),
	EID_TakeHit UMETA(DisplayName = "TakeHit"),
	EID_Blocked UMETA(DisplayName = "Blocked"),
	EID_Parried UMETA(DisplayName = "Parried"),
	EID_ComposureBreaking UMETA(DisplayName = "ComposureBreaking"),
	EID_ComposureBroken UMETA(DisplayName = "ComposureBroken"),
};