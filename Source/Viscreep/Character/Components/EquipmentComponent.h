// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../EnumLibrary/EnumLibrary.h"
#include "../../EnumLibrary/CharacterEnums.h"
#include "InventoryComponent.h"
#include "EquipmentComponent.generated.h"

class ABaseWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VISCREEP_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEquipmentComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EEquipmentSlot, FSlotItemStruct> EquippedItems;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<int, FSlotItemStruct> QuickslotItems;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintreadOnly)
	int QuickslotAmount;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
