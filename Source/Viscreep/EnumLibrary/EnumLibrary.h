#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/EnumAsByte.h"
#include "UObject/Class.h"
#include "CombatEnums.h"
#include "EnumLibrary.generated.h"

/***
*Equipment And Inventory Enums 
***/

UENUM(BlueprintType)
enum class EItemMeshType : uint8
{
	EIMT_None UMETA(DisplayName = "None"),
	EIMT_StaticMesh UMETA(DisplayName = "StaticMesh"),
	EIMT_SkeletalMesh UMETA(DisplayName = "SkeletalMesh"),
};

UENUM(BlueprintType)
enum class EArmorClass : uint8
{
	EAC_None UMETA(DisplayName = "None"),
	EAC_Light UMETA(DisplayName = "Light"),
	EAC_Medium UMETA(DisplayName = "Medium"),
	EAC_Heavy UMETA(DisplayName = "Heavy")
};

UENUM(BlueprintType)
enum class ECurrentAmmoType : uint8
{
	ECAT_None UMETA(DisplayName = "None"),
	ECAT_Ballistic UMETA(DisplayName = "Ballistic"),
	ECAT_Energy UMETA(DisplayName = "Energy"),
	ECAT_Elemental UMETA(DisplayName = "Elemental"),
	ECAT_NonDamaging UMETA(DisplayName = "NonDamaging"),
};

UENUM(BlueprintType)
enum class EEquipSocketOption : uint8
{
	EESO_None UMETA(DisplayName = "None"),
	EESO_OneHandedSocket UMETA(DisplayName = "OneHandedSocket"),
	EESO_TwoHandedBaseGripSocket UMETA(DisplayName = "TwoHandedBaseGripSocket"),
	EESO_TwoHandedPoleGripSocket UMETA(DisplayName = "TwoHandedPoleGripSocket")
};

UENUM(BlueprintType)
enum class EUnequipSocketOption : uint8
{
	EUS_None UMETA(DisplayName = "None"),
	EUS_HipSocket UMETA(DisplayName = "HipSocket"),
	EUS_BackSocket UMETA(DisplayName = "BackSocket")
};

UENUM(BlueprintType)
enum class EInventoryType : uint8
{
	EIT_None UMETA(DisplayName = "None"),
	EIT_General UMETA(DisplayName = "General"),
	EIT_QuickSlot UMETA(DisplayName = "QuickSlot"),
	EIT_Equipped UMETA(DisplayName = "Equipped")
};

UENUM(BlueprintType)
enum class EEquipmentSlot : uint8
{
	EES_Head UMETA(DisplayName = "Head"),
	EES_Neck UMETA(DisplayName = "Neck"),
	EES_UpperBody UMETA(DisplayName = "Chest"),
	EES_Shoulders UMETA(DisplayName = "Shoulders"),
	EES_Arms UMETA(DisplayName = "Arms"),
	EES_Hands UMETA(DisplayName = "Hands"),
	EES_Legs UMETA(DisplayName = "Legs"),
	EES_Feet UMETA(DisplayName = "Feet"),
	EES_OffhandTool UMETA(DisplayName = "OffhandTool"),
	EES_WeaponSlot UMETA(DisplayName = "WeaponSlot"),
	EES_RingOne UMETA(DisplayName = "RingOne"),
	EES_RingTwo UMETA(DisplayName = "RingTwo"),
	EES_Pendant UMETA(DisplayName = "Pendant"),
	EES_BackPack UMETA(DisplayName = "BackPack"),
	EES_WaistPack UMETA(DisplayName = "WaistPack")
};
UENUM(BlueprintType)
enum class EWeaponEquipType : uint8
{
	EWET_None UMETA(DisplayName = "None"),
	EWET_OneHanded UMETA(DisplayName = "OneHanded"),
	EWET_TwoHanded UMETA(DisplayName = "TwoHanded"),
	EWET_Either UMETA(DisplayName = "Either")

};
UENUM(BlueprintType)
enum class EEquipmentLayerType : uint8
{
	EEL_Under UMETA(DisplayName = "Under"),
	EEL_Middle UMETA(DisplayName = "Middle"), 
	EEL_Outer UMETA(DisplayName = "Outer") 
};

/***
* Interaction Enums
***/
UENUM(BlueprintType)
enum class EAllInteractionTypes : uint8
{
	EAIT_None UMETA(DisplayName = "None"),
	EAIT_PickUpActor UMETA(DisplayName = "PickUpActor"),
	EAIT_Door UMETA(DisplayName = "Door"),
	EAIT_LargeChest UMETA(DisplayName = "LargeChest"),
	EAIT_SmallChest UMETA(DisplayName = "SmallChest"),
	EAIT_Cabinet UMETA(DisplayName = "Cabinet"),
	EAIT_Drawer UMETA(DisplayName = "Drawer"),
	EAIT_Chair UMETA(DisplayName = "Chair"),
	EAIT_Couch UMETA(DisplayName = "Couch"),
	EAIT_Bed UMETA(DisplayName = "Bed"),
};

UENUM(BlueprintType)
enum class EInventoryMenuType : uint8
{
	EIMT_DefaultInventory UMETA(DisplayName = "DefaultInventory"),
	EIMT_PurchaseItems UMETA(DisplayName = "PurchaseItems"),
	EIMT_GiveOrSellItems UMETA(DisplayName = "GiveOrSellItems"),
};

/***
* Other Enums
***/

UENUM(BlueprintType)
enum class EMaterialType : uint8
{
	EMT_None UMETA(DisplayName = "None"),
	EMT_Copper UMETA(DisplayName = "Copper"),
	EMT_Bronze UMETA(DisplayName = "Bronze"),
	EMT_Iron UMETA(DisplayName = "Iron"),
	EMT_Steel UMETA(DisplayName = "Steel"),
	EMT_Tungsten UMETA(DisplayName = "Tungsten"),
	EMT_Silver UMETA(DisplayName = "Silver"),
	EMT_Leather UMETA(DisplayName = "Leather"),
	EMT_Cloth UMETA(DisplayName = "Cloth"),
	EMT_Wood UMETA(DisplayName = "Wood"),
	EMT_Stone UMETA(DisplayName = "Stone"),
	EMT_NotRelavant UMETA(DisplayName = "NotRelavant")
};

UENUM(BlueprintType)
enum class EMenutype : uint8
{
	EMT_None UMETA(DisplayName = "None"),
	EMT_PauseMenu UMETA(DisplayName = "PauseMenu"),
	EMT_InventoryMenu UMETA(DisplayName = "InventoryMenu"),
	EMT_ConfirmationMenu UMETA(DisplayName = "ConfirmationMenu"),
	EMT_OptionsMenu UMETA(DisplayName = "OptionsMenu"),
	EMT_ControlsMenu UMETA(DisplayName = "ControlsMenu"),
	EMT_DialogueMenu UMETA(DisplayName = "DialogueMenu"),
	EMT_RebirthMenu UMETA(DisplayName = "RebirthMenu"),
	EMT_MerchantMenu UMETA(DisplayName = "MerchantMenu"),
	EMT_BuildingMenu UMETA(DisplayName = "BuildingMenu"),
	EMT_MainMenu UMETA(DisplayName = "MainMenu"),
	EMT_NewGameMenu UMETA(DisplayName = "NewGameMenu"),
	EMT_LoadingScreen UMETA(DisplayName = "LoadingScreen"),
};

UENUM(BlueprintType)
enum class EProjectileStateType : uint8
{
	EPST_None UMETA(DisplayName = "None"),
	EPST_Unobtained UMETA(DisplayName = "Unobtained"),
	EPST_InWeapon UMETA(DisplayName = "InWeapon"),
	EPST_InAir UMETA(DisplayName = "InAir"),
	EPST_InHand UMETA(DisplayName = "InHand"),
	EPST_StuckInObject UMETA(DisplayName = "StuckInObject"),
};

UENUM(BlueprintType)
enum class EStatusEffects : uint8
{
	ESE_None UMETA(DisplayName = "None"),
	ESE_Burning UMETA(DisplayName = "Burning"),
	ESE_MutationPotion UMETA(DisplayName = "MutationPotion"),
	ESE_Bleeding UMETA(DisplayName = "Bleeding"),
	ESE_CureBleeding UMETA(DisplayName = "CureBleeding"),
	ESE_RestoreBlood UMETA(DisplayName = "RestoreBlood"),
	ESE_Oily UMETA(DisplayName = "Oily"),
	ESE_Wet UMETA(DisplayName = "Wet"),
	ESE_Tired UMETA(DisplayName = "Tired"),
	ESE_Rested UMETA(DisplayName = "Rested"),
	ESE_Hungry UMETA(DisplayName = "Hungry"),
	ESE_Thirsty UMETA(DisplayName = "Thirsty"),
	ESE_WellFed UMETA(DisplayName = "WellFed"),
};

UENUM(BlueprintType)
enum class ECollisionTraceTarget : uint8
{
	ECTT_None UMETA(DisplayName = "None"),
	ECTT_RightWeapon UMETA(DisplayName = "RightWeapon"),
	ECTT_OffHandTool UMETA(DisplayName = "OffHandTool"),
	ECTT_RightHand UMETA(DisplayName = "RightHand"),
	ECTT_LeftHand UMETA(DisplayName = "LeftHand"),
	ECTT_RightFoot UMETA(DisplayName = "RightFoot"),
	ECTT_LeftFoot UMETA(DisplayName = "LeftFoot"),
	ECTT_RightElbow UMETA(DisplayName = "RightElbow"),
	ECTT_Leftelbow UMETA(DisplayName = "LeftElbow"),
	ECTT_RightShoulder UMETA(DisplayName = "RightShoulder"),
	ECTT_LeftShoulder UMETA(DisplayName = "LeftShoulder")
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	EIT_None UMETA(DisplayName = "None"),
	EIT_MeleeWeapon UMETA(DisplayName = "MeleeWeapon"),
	EIT_Armor UMETA(DisplayName = "Armor"),
	EIT_RightHandRangedWeapon UMETA(DisplayName = "RightHandRangedWeapon"),
	EIT_OffHandTool UMETA(DisplayName = "OffHandTool"),
	EIT_Consumable UMETA(DisplayName = "Consumable"),
	EIT_Ammo UMETA(DisplayName = "Ammo"),
	EIT_Bag UMETA(DisplayName = "Bag"),
	EIT_Battery UMETA(DisplayName = "Batery"),
	EIT_Ring UMETA(DisplayName = "Ring"),
	EIT_Pendant UMETA(DisplayName = "Pendant")
};
UENUM(BlueprintType)
enum class EItemUseType : uint8
{
	EIUT_None UMETA(DisplayName = "None"),
	EIUT_Wearable UMETA(DisplayName = "Wearable"),
	EIUT_Wieldable UMETA(DisplayName = "Wieldable"),
	EIUT_Eatible UMETA(DisplayName = "Eatible"),
	EIUT_Drinkable UMETA(DisplayName = "Drinkable"),
	EIUT_Abusable UMETA(DisplayName = "Abusable"),
	EIUT_Deployable UMETA(DisplayName = "Deployable"),
	EIUT_Plantable UMETA(DisplayName = "Plantable")
};

UENUM(BlueprintType)
enum class EBufferKey : uint8
{
	EBK_None UMETA(DisplayName = "None"),
	EBK_Attack UMETA(DisplayName = "Attack"),
	EBK_PrimaryAttack UMETA(DisplayName = "PrimaryAttack"),
	EBK_Dodge UMETA(DisplayName = "Dodge"),
	EBK_Parry UMETA(DisplayName = "Parry"),
	EBK_Jump UMETA(DisplayName = "Jump"),
	EBK_UseItem UMETA(DisplayName = "UseItem"),
	EBK_SwitchQuickslotItem UMETA(DisplayName = "SwitchQuickslotItem"),
	EBK_ConsumeItem UMETA(DisplayName = "ConsumeItem"),
	EBK_Interact UMETA(DisplayName = "Interact"),
	EBK_ToggleCombatMode UMETA(DisplayName = "ToggleCombatMode"),
	EBK_GetUp UMETA(DisplayName = "GetUp"),
	EBK_UseLeftHandTool UMETA(DisplayName = "UseLeftHandTool"),
	EBK_Zoom UMETA(DisplayName = "Zoom"),
	EBK_Aim UMETA(DisplayName = "Aim"),
};

UENUM(BlueprintType)
enum class EAuxBufferKey : uint8
{
	EABK_None UMETA(DisplayName = "None"),
	EABK_Forward UMETA(DisplayName = "None"),
	EABK_Back UMETA(DisplayName = "None"),
	EABK_Left UMETA(DisplayName = "None"),
	EABK_Right UMETA(DisplayName = "None"),
	EABK_HoldingHotkeyButton UMETA(DisplayName = "None"),
};