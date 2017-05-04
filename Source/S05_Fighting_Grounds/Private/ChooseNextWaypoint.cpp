// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Fighting_Grounds.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolRoute.h"
#include "AIController.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	//Get Patrol Route
	auto GuardAIController = OwnerComp.GetAIOwner()->GetPawn();
	if (!ensure(GuardAIController)) { return EBTNodeResult::Failed; }
	auto PatrolRouteComp = GuardAIController->FindComponentByClass<UPatrolRoute>();

	PatrolPoints = PatrolRouteComp->GetPatrolPoints();

	//Protects against no patrol points being set
	if (PatrolPoints.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("Missing patrol routes on a guard"));
		return EBTNodeResult::Failed;
	}

	//Set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycles the waypoints
	Index++;
	//Uses modulus to see what point to go to based on the remainder of the division
	auto NewIndex = Index%PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NewIndex);
	
	return EBTNodeResult::Succeeded;
}


