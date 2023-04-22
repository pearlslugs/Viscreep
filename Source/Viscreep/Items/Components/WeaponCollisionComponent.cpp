// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponCollisionComponent.h"
#include "Engine/StaticMeshSocket.h"
#include "Math/TransformNonVectorized.h"
#include "../../Character/Interface/RPGInterface.h"
#include "Components/SkinnedMeshComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UWeaponCollisionComponent::UWeaponCollisionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponCollisionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponCollisionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsTraceOpen)
	{
		UWeaponCollisionComponent::TraceForHits();
	}

	// ...
}

void UWeaponCollisionComponent::InitializeCollisionComponent(bool InIsStaticMesh, UStaticMeshComponent* InItemMesh, USkeletalMeshComponent* InSKMesh)
{
	IsStaticMesh = InIsStaticMesh;
	if (InIsStaticMesh)
	{
		ItemStaticMesh = InItemMesh;
		StartSocket = InItemMesh->GetStaticMesh()->FindSocket(StartSocketName);
		EndSocket = InItemMesh->GetStaticMesh()->FindSocket(EndSocketName);
		
	}
	else
	{
		// get bone locations
	}
}

void UWeaponCollisionComponent::TraceForHits()
{
	if (IsStaticMesh)
	{
		if (ItemStaticMesh)
		{
			// if item doesnt have attack type change socket
				// dont save the static mesh component, save the socket
			TArray<FHitResult> OutHits;
			FTransform StartTransform;
			StartSocket->GetSocketTransform(StartTransform, ItemStaticMesh);
			FTransform EndTransform;
			EndSocket->GetSocketTransform(EndTransform, ItemStaticMesh);
			FCollisionObjectQueryParams CollisionParams = FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn);
			FCollisionQueryParams TraceParams(FName(TEXT("")), false, OwnerActor);
			
			//DrawDebugLine(GetWorld(), StartTransform.GetLocation(), EndTransform.GetLocation(), FColor::Green, false, 1, 0, 1);
			
			if (GetWorld()->LineTraceMultiByObjectType(OutHits, StartTransform.GetLocation(), EndTransform.GetLocation(), CollisionParams, TraceParams))
			{
				if (OutHits.Num() > 0)
				{
					for(auto Hit : OutHits)
						if (Hit.GetActor() && !IgnoredActors.Contains(Hit.GetActor()))
						{
							IgnoredActors.Add(Hit.GetActor());
							if (GEngine)
							{								
								HitTraceResults.HitLocation = Hit.Location;
								IRPGInterface* InterfaceActor = Cast<IRPGInterface>(Hit.GetActor());
								if (InterfaceActor)
								{
									HitTraceResults.HitBone = InterfaceActor->GetSkinnedMesh()->FindClosestBone(Hit.Location);
								}
								OnWeaponHitActor.Broadcast(Hit.GetActor(), HitTraceResults);
							}
						}
				}
			}
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("NoStaticMesh")));
		}
	}
}

void UWeaponCollisionComponent::ToggleGate(bool Open)
{
	IsTraceOpen = Open;
	if (!Open)
	{
		IgnoredActors.Empty();
	}
}

void UWeaponCollisionComponent::InitializeStaticMesh(UStaticMeshComponent* InMesh)
{
	if (InMesh)
	{
		ItemStaticMesh = InMesh;
		EndSocket = InMesh->GetSocketByName(EndSocketName);
		StartSocket = InMesh->GetSocketByName(StartSocketName);
	}
}