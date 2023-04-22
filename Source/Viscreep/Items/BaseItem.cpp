// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseItem.h"
#include "Engine/StaticMesh.h"
#include "Engine/SkeletalMesh.h"

// Sets default values for this component's properties
ABaseItem::ABaseItem()
{
	CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	ItemSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	ItemStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	ItemSkeletalMesh->SetupAttachment(RootComponent);
	ItemStaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ...
}

bool ABaseItem::AttachActor(FName InSocketName)
{
	if (OwnerMesh)
	{
		FAttachmentTransformRules Rules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
		AttachToComponent(OwnerMesh, Rules, InSocketName);
		return true;
	}
	return false;
}




