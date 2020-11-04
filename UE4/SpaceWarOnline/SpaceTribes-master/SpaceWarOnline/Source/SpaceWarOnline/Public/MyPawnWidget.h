// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyPawnWidget.generated.h"

class APawn;
/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API UMyPawnWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UMyPawnWidget(const FObjectInitializer& Initializer);
	
public:
	virtual void Configurate(APawn* Pawn);
};

