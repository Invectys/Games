// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorWithGravity.h"
#include "MyActorGravityComponent.h"

AMyActorWithGravity::AMyActorWithGravity(const FObjectInitializer& Initializer) : Super(Initializer)
{
	GravityComponent = CreateDefaultSubobject<UMyActorGravityComponent>(TEXT("Gravity Component"));
}

void AMyActorWithGravity::BeginPlay()
{
	Super::BeginPlay();
}