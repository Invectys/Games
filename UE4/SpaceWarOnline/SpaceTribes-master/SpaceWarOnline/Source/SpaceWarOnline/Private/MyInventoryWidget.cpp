// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryWidget.h"
#include "MyInventoryComponent.h"

void UMyInventoryWidget::Configurate(UMyInventoryComponent* InventoryComp)
{
	Inventory = InventoryComp;
}