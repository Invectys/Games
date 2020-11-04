// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawnShipWidget.h"
#include "MyShip.h"
#include "GameFramework/Pawn.h"
#include "MyInventoryComponent.h"

void UMyPawnShipWidget::Configurate(APawn* Pawn)
{
	Super::Configurate(Pawn);

	AMyShip* Ship = Cast<AMyShip>(Pawn);
	if (IsValid(Ship))
	{
		Inventory = Ship->getInventory();
		
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Widget added for not MyShip Change Widget Type or Pawn"));
	}
}