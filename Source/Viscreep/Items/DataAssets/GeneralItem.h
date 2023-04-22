// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Misc/Guid.h"
#include "Styling/SlateBrush.h"
#include "../../EnumLibrary/EnumLibrary.h"
#include "../../StructLibrary/StructLibrary.h"
#include "GeneralItem.generated.h"

/**
 * 
 */
UCLASS()
class VISCREEP_API UGeneralItem : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	UStaticMeshComponent* ItemStaticMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	USkeletalMeshComponent* ItemSkeletalMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	EItemMeshType CurrentMeshType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	bool IsEquipped;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	EWeaponEquipType WeaponEquipType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	bool IsHidden;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	FTransform RelativeTransform;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	FGuid ItemGUID;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	EItemType CurrentItemType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	FName ItemName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	FName ItemDescription;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	FSlateBrush ItemIcon;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	EItemUseType ItemUseType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	int MaxCountPerStack;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	int CurrentAmount;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	int SlotLength = 1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	int SlotWidth = 1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	int Weight;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	EEquipmentSlot ItemEquipSlot;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	EEquipSocketOption ItemEquipSocket;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	EUnequipSocketOption ItemUnequipSocket;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WeaponData")
	FWeaponData CurrentWeaponData;
};
