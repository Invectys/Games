// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDrop.h"
#include "MyDropPart.generated.h"

USTRUCT(BlueprintType)
struct FPartStruct
{
	GENERATED_USTRUCT_BODY()

	FPartStruct()
	{
		MassInKg = 5;
	}

	UPROPERTY(BlueprintReadWrite)
		int MassInKg;

};

/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyDropPart : public AMyDrop
{
	GENERATED_BODY()
	
};
