// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logic/BaseItemInterface.h"
#include "DataAssets/GeneralItem.h"
#include "GameFramework/Character.h"
#include "BaseItem.generated.h"

class EquipmentComponent;

UCLASS()
class VISCREEP_API ABaseItem : public AActor, public IBaseItemInterface
{
	GENERATED_BODY()
	
public:
	ABaseItem();
	USkeletalMeshComponent* ItemSkeletalMesh;
	UStaticMeshComponent* ItemStaticMesh;
	EquipmentComponent* OwnerEquipment;
	UGeneralItem* ContainedDataAsset;

	USkeletalMeshComponent* OwnerMesh = nullptr;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool AttachActor(FName SocketName);
	ACharacter* GetOwnerCharacter();
	UPrimitiveComponent* GetItemMeshComponent();
	void UpdateItemMesh();
	void SimulatePhysicsOnItemMesh();
	
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
