// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCanBeDestroyedActor.h"
#include "MyCanBeDestroyedComponent.h"

AMyCanBeDestroyedActor::AMyCanBeDestroyedActor(const FObjectInitializer& Initializer) : Super(Initializer)
{
	MeDestroyerComponent = CreateDefaultSubobject<UMyCanBeDestroyedComponent>(TEXT("MeDestroyer"));
}

float AMyCanBeDestroyedActor::TakeDamage(
	float DamageAmount,
	FDamageEvent const& DamageEvent,
	AController* EventInstigator,
	AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	return 0.0f;
}
