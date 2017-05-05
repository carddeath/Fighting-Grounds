// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/************************************************************************/
/* A "Root Planner" for the AI to choosen their next waypoint                                                                     */
/************************************************************************/
UCLASS( ClassGroup=(PatrolSystem), meta=(BlueprintSpawnableComponent) )
class S05_FIGHTING_GROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	



	TArray<AActor*> GetPatrolPoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
		TArray<AActor*> PatrolPointsCPP;
	
};
