// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../StructLibrary/StructLibrary.h"
#include "WeaponCollisionComponent.generated.h"

class UStaticMeshSocket;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeaponHitActor, AActor*, HitActor, FHitTraceResults, HitResults);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VISCREEP_API UWeaponCollisionComponent : public UActorComponent
{
	GENERATED_BODY()



public:	
	// Sets default values for this component's properties
	UWeaponCollisionComponent();


	// initialization
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName StartSocketName = FName("StartSocket");
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName EndSocketName = FName("EndSocket");
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName AttackTypeSwitchSocketName = FName("AttackTypeSwitchSocket");
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool IsStaticMesh = true;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UStaticMeshComponent* ItemStaticMesh;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	USkeletalMeshComponent* ItemSkeletalMesh;
	UFUNCTION(BlueprintCallable)
	void InitializeCollisionComponent(bool InIsStaticMesh, UStaticMeshComponent* InItemMesh, USkeletalMeshComponent* InSKMesh);
	UFUNCTION(BlueprintCallable)
	void TraceForHits();
	UFUNCTION(BlueprintCallable)
	void ToggleGate(bool Open);

	// trace
	TArray<AActor*> IgnoredActors;
	UFUNCTION(BlueprintCallable)
		FORCEINLINE void SetActorOwner(AActor* InActor) { OwnerActor = InActor; }

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		AActor* OwnerActor;

	bool IsTraceOpen;
	FHitTraceResults HitTraceResults;
	UFUNCTION(BlueprintCallable)
	void InitializeStaticMesh(UStaticMeshComponent* InStaticMesh);

	UPROPERTY(BlueprintAssignable)
	FOnWeaponHitActor OnWeaponHitActor;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
	const UStaticMeshSocket* StartSocket;
	const UStaticMeshSocket* EndSocket;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
