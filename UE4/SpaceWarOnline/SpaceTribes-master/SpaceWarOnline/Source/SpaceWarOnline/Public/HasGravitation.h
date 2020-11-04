// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HasGravitation.generated.h"

class UMyActorGravityComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI,Blueprintable)
class UHasGravitation : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPACEWARONLINE_API IHasGravitation
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UMyActorGravityComponent* getGravityComponent() const;


};
