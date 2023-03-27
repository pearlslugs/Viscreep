// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "../Components/InputBufferComponent.h"
#include "../Components/CombatComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PlayerInputBufferComponent = CreateDefaultSubobject<UInputBufferComponent>(TEXT("PlayerInputBufferComponent"));
	PlayerCombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("PlayerCombatComponent"));

}

// Called when the game starts
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ...
}


