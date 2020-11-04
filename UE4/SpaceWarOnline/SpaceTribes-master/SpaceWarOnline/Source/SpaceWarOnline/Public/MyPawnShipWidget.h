// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawnWidget.h"
#include "MyPawnShipWidget.generated.h"

struct FSlotStruct;
class UMyInventoryComponent;
class APawn;
/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API UMyPawnShipWidget : public UMyPawnWidget
{
	GENERATED_BODY()
	
public:

	virtual void Configurate(APawn* Pawn) override;

	

public:
	UPROPERTY(EditAnyWhere,BlueprintReadOnly)
		UMyInventoryComponent* Inventory;

};
