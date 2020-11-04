// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HasWeapons.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHasWeapons : public UInterface
{
	GENERATED_BODY()
};

class UMyWeaponComponent;
/**
 * 
 */
class SPACEWARONLINE_API IHasWeapons
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UMyWeaponComponent* getWeapon1() ;
	virtual UMyWeaponComponent* getWeapon2() ;
	virtual UMyWeaponComponent* getWeapon3() ;
};
