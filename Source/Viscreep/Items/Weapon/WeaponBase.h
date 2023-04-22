// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseItem.h"
#include "../../StructLibrary/StructLibrary.h"
#include "../Components/WeaponCollisionComponent.h"
#include "WeaponBase.generated.h"

/**
 * 
 */

UCLASS()
class VISCREEP_API AWeaponBase : public ABaseItem
{
	GENERATED_BODY()
public:
	AWeaponBase();
	UPROPERTY(BlueprintReadOnly)
	UWeaponCollisionComponent* WeaponCollision;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FAttackTraceStruct AttackTraceParams;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FOutgoingAttackStruct OutgoingAttackParams;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FWeaponData WeaponData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* ActorOwner;
	UFUNCTION(BlueprintCallable)
		FORCEINLINE void SetActorOwner(AActor* InActor) { Owner = InActor; WeaponCollision->SetActorOwner(InActor); }

	FOutgoingAttackStruct MakeAttack(FOutgoingAttackStruct InProgressAttack);
};
