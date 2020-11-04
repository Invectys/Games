// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDropPart.h"
#include "MyDropPartArmor.generated.h"

USTRUCT(BlueprintType)
struct FPartArmorStruct : public FPartStruct {
	GENERATED_USTRUCT_BODY()
		FPartArmorStruct()
	{
		MaxArmor = 400;
		Strenght = 1;
	}

	UPROPERTY(BlueprintReadWrite)
		float MaxArmor;
	UPROPERTY(BlueprintReadWrite)
		float Strenght;
};

/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyDropPartArmor : public AMyDropPart
{
	GENERATED_BODY()
public:



private:
	UPROPERTY()
		FPartArmorStruct ArmorInfo;



public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
		FPartArmorStruct getArmorInfo(){ return ArmorInfo; }
};
