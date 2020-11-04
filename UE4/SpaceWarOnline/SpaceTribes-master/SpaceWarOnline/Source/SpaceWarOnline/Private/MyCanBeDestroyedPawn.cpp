// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCanBeDestroyedPawn.h"
#include "MyCanBeDestroyedComponent.h"

AMyCanBeDestroyedPawn::AMyCanBeDestroyedPawn(const FObjectInitializer& Initializer) : Super(Initializer)
{
	MeDestroyerComponent = CreateDefaultSubobject<UMyCanBeDestroyedComponent>(TEXT("MeDestroyer"));
}

float AMyCanBeDestroyedPawn::TakeDamage(
	float DamageAmount, 
	FDamageEvent const& DamageEvent, 
	AController* EventInstigator, 
	AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	return 0.0f;
}
