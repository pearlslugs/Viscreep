// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../EnumLibrary/EnumLibrary.h"
#include "InputBufferComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBufferConsumed, EBufferKey, KeyToConsume);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBufferSwitch, bool, BufferState);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VISCREEP_API UInputBufferComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInputBufferComponent();

	UPROPERTY(BlueprintAssignable)
	FOnBufferConsumed OnBufferConsumed;
	UPROPERTY(BlueprintAssignable)
	FOnBufferSwitch OnBufferSwitch;
	UFUNCTION(BlueprintCallable)
	void OpenBuffer();
	UFUNCTION(BlueprintCallable)
	void ConsumeBuffer();
	UFUNCTION(BlueprintCallable)
	void PreventEarlyInput();

	UFUNCTION(BlueprintCallable)
	void AcceptKey(EBufferKey InKey);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	EBufferKey CurrentKey;
	bool IsBufferOpen;
	bool ShouldConsumeCurrentKey;
	bool CanChangeKey; // may be redundant
	bool IsInputQued;

	EAuxBufferKey CurrentAuxBufferKey;
	bool CanUseAuxInput;

	UFUNCTION()
	bool CompareKeys(EBufferKey IncomingKey);
	bool GetIsHighPriorityInput(EBufferKey IncomingKey);

	
	UFUNCTION()
	void CloseBuffer();
	
	UFUNCTION()
	void ClearBuffer();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
