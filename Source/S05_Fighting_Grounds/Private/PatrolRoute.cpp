// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Fighting_Grounds.h"
#include "PatrolRoute.h"

TArray<AActor*> UPatrolRoute::GetPatrolPoints() const {
	return PatrolPointsCPP;
}

