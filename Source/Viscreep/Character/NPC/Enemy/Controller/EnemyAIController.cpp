// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "../../BaseNonPlayableCharacter.h"

AEnemyAIController::AEnemyAIController(FObjectInitializer const& ObjectInitialize)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("/Script/AIModule.BehaviorTree'/Game/Characters/NPC/Enemy/Controller/HumanoidEnemyAI.HumanoidEnemyAI'"));
}

void AEnemyAIController::BeginPlay()
{

}

void AEnemyAIController::OnPossess(APawn* const PossesedPawn)
{

}

UBlackboardComponent* AEnemyAIController::GetBlackBoard() const
{
	return BlackBoardComponent;
}