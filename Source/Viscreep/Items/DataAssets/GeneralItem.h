// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Misc/Guid.h"
#include "Styling/SlateBrush.h"
#include "../../EnumLibrary/EnumLibrary.h"
#include "GeneralItem.generated.h"

/**
 * 
 */
UCLASS()
class VISCREEP_API UGeneralItem : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UStaticMeshComponent* ItemStaticMesh;
	USkeletalMeshComponent* ItemSkeletalMesh;
	EItemMeshType CurrentMeshType;

	bool IsEquipped;
	EWeaponEquipType WeaponEquipType;
	bool IsHidden;
	FTransform* RelativeTransform;
	FGuid ItemGUID;
	EItemType CurrentItemType;
	FName ItemName;
	FName ItemDescription;
	FSlateBrush ItemIcon;
	EItemUseType* ItemUseType;
	int MaxCountPerStack;
	int CurrentAmount;
	int SlotLength = 1;
	int SlotWidth = 1;
	int Weight;
	EEquipmentSlot ItemEquipSlot;
	EEquipSocketOption ItemEquipSocket;
	EUnequipSocketOption ItemUnequipSocket;
};
