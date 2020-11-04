// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyUserWidget.h"
#include "MyInventoryWidget.generated.h"

class UMyInventoryComponent;
/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API UMyInventoryWidget : public UMyUserWidget
{
	GENERATED_BODY()
	
public:
	void Configurate(UMyInventoryComponent* InventoryComp);
	


public:
	UPROPERTY(BlueprintReadOnly)
		UMyInventoryComponent* Inventory;
};
