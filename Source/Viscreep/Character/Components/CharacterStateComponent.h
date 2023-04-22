// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../EnumLibrary/CharacterEnums.h"
#include "CharacterStateComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGeneralStateChange, ECharacterGeneralState, NewState);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VISCREEP_API UCharacterStateComponent : public UActorComponent
{

	GENERATED_BODY()
	

public:	
	// Sets default values for this component's properties
	UCharacterStateComponent();

	// delagates
	UPROPERTY(BlueprintAssignable)
	FOnGeneralStateChange OnGeneralStateChanged;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack|Position")
	ECharacterGeneralState CurrentCharacterGeneralState;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack|Position")
	ECombatState CurrentCombatState;

	UFUNCTION(BlueprintCallable)
	void ChangeGeneralCharacterState(ECharacterGeneralState NewState);
	UFUNCTION(BlueprintCallable)
	void UpdateCombatState(ECombatState NewState)
	{
		CurrentCombatState = NewState;
	}
	UFUNCTION(BlueprintPure)
	ECombatState GetCombatState()
	{
		return CurrentCombatState;
	}
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHostilityTeam CurrentHostility;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
