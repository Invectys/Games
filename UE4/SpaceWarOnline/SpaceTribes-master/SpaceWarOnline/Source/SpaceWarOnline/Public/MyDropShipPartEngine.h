// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDropShipPart.h"
#include "MyDropShipPartEngine.generated.h"


USTRUCT(BlueprintType)
struct FShipPartEngineStruct : public FShipPartStruct {

	GENERATED_USTRUCT_BODY()

	FShipPartEngineStruct();


	UPROPERTY()
		float Throttle;
	UPROPERTY()
		float TurnTorque;
	
};

/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyDropShipPartEngine : public AMyDropShipPart
{
	GENERATED_BODY()
public:


private:
	FShipPartEngineStruct Info;
};
