// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyHUD.h"
#include "MyGameHUD.generated.h"


class UMyPawnWidget;
class UMyInventoryWidget;

UCLASS()
class SPACEWARONLINE_API AMyGameHUD : public AMyHUD
{
	GENERATED_BODY()
public:
	AMyGameHUD(const FObjectInitializer& Initializer);


public:

	UFUNCTION(BlueprintCallable)
		void AddPawnWidget(AMyPawn* For);
	UFUNCTION(BlueprintCallable)
		void AddInventoryWidget(APawn* Pawn);
	UFUNCTION(BlueprintCallable)
		void RemoveInventoryWidget();
public:
	

	UPROPERTY(BlueprintReadOnly)
		UMyPawnWidget* wPawn;
	UPROPERTY(EditAnyWhere,BlueprintReadOnly)
		UMyInventoryWidget* wInventory;
	UPROPERTY(EditAnyWhere,BlueprintreadWrite)
		TSubclassOf<UMyInventoryWidget> InventoryWidgetClass;


public:
	UFUNCTION()
		bool isInventoryAdded();
};
