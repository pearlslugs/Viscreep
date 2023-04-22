// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logic/BaseItemInterface.h"
#include "DataAssets/GeneralItem.h"
#include "GameFramework/Character.h"
#include "BaseItem.generated.h"

class UEquipmentComponent;

UCLASS()
class VISCREEP_API ABaseItem : public AActor, public IBaseItemInterface
{
	GENERATED_BODY()
	
public:
	ABaseItem();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USkeletalMeshComponent* ItemSkeletalMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* ItemStaticMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UEquipmentComponent* OwnerEquipment;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGeneralItem* ContainedDataAsset;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USkeletalMeshComponent* OwnerMesh = nullptr;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool AttachActor(FName SocketName);
	
	
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
