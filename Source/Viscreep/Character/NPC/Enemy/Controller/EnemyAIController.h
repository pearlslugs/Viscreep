// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */

class UBlackboardComponent;
class UBehaviorTreeComponent;
class UBehaviorTree;

UCLASS()
class VISCREEP_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	AEnemyAIController(FObjectInitializer const& ObjectInitializer = FObjectInitializer::Get());
	void BeginPlay() override;
	void OnPossess(APawn* const PossesedPawn) override;
	UBlackboardComponent* GetBlackBoard() const;

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTreeComponent* BehaviorTreeComponent;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviorTree;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBlackboardComponent* BlackBoardComponent;
};
