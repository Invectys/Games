// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyWeaponComponent.h"

#include "MyDropPartWeaponLaserGun.h"


#include "MyWeaponLaserGunComponent.generated.h"

struct FWeaponLaserGunStruct;
/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API UMyWeaponLaserGunComponent : public UMyWeaponComponent
{
	GENERATED_BODY()
public:

public:
	virtual void Shoot() override;

private:
	UPROPERTY()
	FWeaponLaserGunStruct Info;

public:
	UFUNCTION()
	FWeaponLaserGunStruct getInfo();
};
