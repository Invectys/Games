// Fill out your copyright notice in the Description page of Project Settings.


#include "HasGravitation.h"
#include "MyActorGravityComponent.h"

// Add default functionality here for any IHasGravitation functions that are not pure virtual.
UMyActorGravityComponent* IHasGravitation::getGravityComponent() const
{
	UE_LOG(LogTemp, Error, TEXT("Trying get null Gravity Component!"));
	throw std::exception("Trying get null Gravity Component!");
}