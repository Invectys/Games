// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDropPart.h"
#include "MyDropPartWeapon.generated.h"

USTRUCT(BlueprintType)
struct FPartrWeaponStruct : public FPartStruct
{
	GENERATED_USTRUCT_BODY()
		FPartrWeaponStruct()
	{
		ShootForce = 10000;
	}

	UPROPERTY(BlueprintReadWrite)
		float ShootForce;
};

/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyDropPartWeapon : public AMyDropPart
{
	GENERATED_BODY()
	
};
