// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDropPartWeapon.h"
#include "MyDropPartWeaponLaserGun.generated.h"

USTRUCT(BlueprintType)
struct FWeaponLaserGunStruct : public FPartrWeaponStruct
{
	GENERATED_USTRUCT_BODY()
		FWeaponLaserGunStruct()
	{

	}



};
/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyDropPartWeaponLaserGun : public AMyDropPartWeapon
{
	GENERATED_BODY()
public:



private:
	UPROPERTY()
		FWeaponLaserGunStruct LaserGunInfo;

public:
	FWeaponLaserGunStruct getLaserGunInfo() { return LaserGunInfo; }
};
