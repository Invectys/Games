// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDrop.h"
#include "MyDropMaterial.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class SPACEWARONLINE_API AMyDropMaterial : public AMyDrop
{
	GENERATED_BODY()
public:
	AMyDropMaterial(const FObjectInitializer& Initializer);
};
