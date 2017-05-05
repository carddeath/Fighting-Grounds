// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Fighting_Grounds.h"
#include "Guard.h"


// Sets default values
AGuard::AGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ThirdPersonGun = CreateDefaultSubobject < USkeletalMeshComponent>(FName("AI Gun"));
	ModelMesh = FindComponentByClass<USkeletalMeshComponent>();
	ThirdPersonGun->SetupAttachment(ModelMesh, FName("Gun Socket"));
	ThirdPersonGun->SetOnlyOwnerSee(false);

}

// Called when the game starts or when spawned
void AGuard::BeginPlay()
{
	Super::BeginPlay();

	ThirdPersonGun->AttachToComponent(ModelMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName("Gun Socket"));
	
}

// Called every frame
void AGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGuard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

