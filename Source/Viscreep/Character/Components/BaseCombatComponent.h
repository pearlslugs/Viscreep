// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../EnumLibrary/CombatEnums.h"
#include "../../StructLibrary/StructLibrary.h"
#include "Delegates/Delegate.h"
#include "BaseCombatComponent.generated.h"


//this is broadcasted to the hit reaction compoennt
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHitReactionDecided, EHitReactionCatagory, InitialReaction);

class UBaseStatsComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VISCREEP_API UBaseCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseCombatComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack|Position")
	EAttackPosition CurrentAttackPosition;
	void SetCurrentAttackPosition(EAttackPosition NewPosition);
	EAttackPosition GetCurrentAttackPosition();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Defense|Position")
	EDefensePosition CurrentDefensePosition;
	void SetCurrentDefensePosition(EDefensePosition NewPosition);
	EDefensePosition GetCurrentDefensePosition();
	EDefensePosition PreviousDefensePosition;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FOutgoingAttackStruct IncomingAttack;
	UFUNCTION()
	FOutgoingAttackStruct GetIncomingAttack()
	{
		return IncomingAttack;
	}
	UPROPERTY(BlueprintAssignable)
	FOnHitReactionDecided OnHitReactionDecided;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FAnimMontageStruct SelectedMontage;
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetSelectedMontage(FAnimMontageStruct FoundMontage) { SelectedMontage = FoundMontage; }
	FORCEINLINE FAnimMontageStruct GetSelectedMontage() { return SelectedMontage; }
	

	EAttackPosition DefensePositionToAttackPosition(EDefensePosition);
	UFUNCTION(BlueprintCallable)
	void SetStatsComponent(UBaseStatsComponent* InComponent)
	{
		OwnerStatsComponent = InComponent;
	}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UBaseStatsComponent* OwnerStatsComponent;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION()
	void RecieveAttack(FOutgoingAttackStruct CurrentIncomingAttack);
		
};
