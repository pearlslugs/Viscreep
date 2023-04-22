// Fill out your copyright notice in the Description page of Project Settings.

#include "InputBufferComponent.h"
#include "../../EnumLibrary/EnumLibrary.h"


// Sets default values for this component's properties
UInputBufferComponent::UInputBufferComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	IsBufferOpen = true;
	CanChangeKey = true;

	// ...
}


// Called when the game starts
void UInputBufferComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInputBufferComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInputBufferComponent::AcceptKey(EBufferKey InKey)
{
	if (IsBufferOpen) 
	{

		// store the key for the next use, if the player is already in the middle of doing something, like attacking
		// we will save the key, but not consume. an anim notify at the end of the aniamtion will then consume the current key
		CurrentKey = InKey;
		if (CanChangeKey)
		{
			CanChangeKey = false;
			UInputBufferComponent::ConsumeBuffer();
		}
		
	}
	else if (GetIsHighPriorityInput(InKey))
	{
		IsBufferOpen = true;
		AcceptKey(InKey);
	}
}


void UInputBufferComponent::OpenBuffer()
{
	CurrentKey = EBufferKey::EBK_None;
	IsBufferOpen = true;
	CanChangeKey = false;
}
void UInputBufferComponent::CloseBuffer()
{
	IsBufferOpen = false;
}
void UInputBufferComponent::ConsumeBuffer()
{
	if (CurrentKey != EBufferKey::EBK_None)
	{
		OnBufferConsumed.Broadcast(CurrentKey);
	}
	UInputBufferComponent::ClearBuffer();
}
void UInputBufferComponent::ClearBuffer()
{
	CurrentKey = EBufferKey::EBK_None;
	IsBufferOpen = true;
	CanChangeKey = true;
}

void UInputBufferComponent::PreventEarlyInput()
{
	IsBufferOpen = false;
}

bool UInputBufferComponent::CompareKeys(EBufferKey IncomingKey)
{
	if (UInputBufferComponent::GetIsHighPriorityInput(IncomingKey))
	{
		return true;
	}
	else if (UInputBufferComponent::GetIsHighPriorityInput(CurrentKey))
	{
		return false;
	}
	return true;
}

bool UInputBufferComponent::GetIsHighPriorityInput(EBufferKey IncomingKey)
{
	if (IncomingKey == EBufferKey::EBK_Dodge ||
		IncomingKey == EBufferKey::EBK_ConsumeItem ||
		IncomingKey == EBufferKey::EBK_Parry ||
		IncomingKey == EBufferKey::EBK_Parry
		)
	{
		return true;
	}
	return false;
}