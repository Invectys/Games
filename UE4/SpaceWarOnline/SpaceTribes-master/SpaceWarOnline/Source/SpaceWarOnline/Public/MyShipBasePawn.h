// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawn.h"
#include "MyShipBasePawn.generated.h"

/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyShipBasePawn : public AMyPawn
{
	GENERATED_BODY()
public:
	AMyShipBasePawn(const FObjectInitializer& Initializer);
};
