// Fill out your copyright notice in the Description page of Project Settings.


#include "CanBeDestroyed.h"
#include "MyCanBeDestroyedComponent.h"
// Add default functionality here for any ICanBeDestroyed functions that are not pure virtual.
UMyCanBeDestroyedComponent* ICanBeDestroyed::getCanBeDestroyComponent() const
{
	return NULL;
}