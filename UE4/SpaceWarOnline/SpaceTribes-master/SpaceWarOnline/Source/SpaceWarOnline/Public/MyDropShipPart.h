// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDropPart.h"
#include "MyDropShipPart.generated.h"

USTRUCT(BlueprintType)
struct FShipPartStruct : public FPartStruct {

	GENERATED_USTRUCT_BODY()

	FShipPartStruct();
	
};


/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyDropShipPart : public AMyDropPart
{
	GENERATED_BODY()
	
};
