// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameHUD.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "MyPawn.h"
#include "MyPawnWidget.h"
#include "HasInventory.h"
#include "MyInventoryWidget.h"

AMyGameHUD::AMyGameHUD(const FObjectInitializer& Initializer) : Super(Initializer)
{
	static ConstructorHelpers::FClassFinder<UMyInventoryWidget> InvClass(TEXT("/Game/Grafic/Widjets/Game/Process/MyInventoryWidgetBP"));
	InventoryWidgetClass = InvClass.Class;
}

void AMyGameHUD::AddPawnWidget(AMyPawn* For)
{
	if (IsValid(wPawn))
	{
		wPawn->RemoveFromParent();
	}
	TSubclassOf<UUserWidget> Class = For->getPawnWidgetClass();
	if (IsValid(Class))
	{
		wPawn = CreateWidget<UMyPawnWidget>(PlayerOwner, Class);
		if (IsValid(wPawn))
		{
			wPawn->Configurate(For);
			wPawn->AddToViewport();
		}
	}
	
}

void AMyGameHUD::AddInventoryWidget(APawn* Pawn)
{
	if(Pawn == NULL)Pawn = GetOwningPawn();
	bool bHasInventory = Pawn->GetClass()->ImplementsInterface(UHasInventory::StaticClass());
	if (bHasInventory)
	{
		IHasInventory* Interface = Cast<IHasInventory>(Pawn);
		
		if (IsValid(wInventory))
		{
			wInventory->RemoveFromParent();
		}
		
		if (IsValid(InventoryWidgetClass))
		{
			wInventory = CreateWidget<UMyInventoryWidget>(PlayerOwner, InventoryWidgetClass);
			if (IsValid(wInventory))
			{
				wInventory->Configurate(Interface->getInventory());
				wInventory->AddToViewport();
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Trying add Inventory widget for pawn that has not inventory"));
	}

}
void AMyGameHUD::RemoveInventoryWidget()
{
	wInventory->RemoveFromParent();
}

bool AMyGameHUD::isInventoryAdded()
{
	if (IsValid(wInventory))
	{
		return wInventory->IsInViewport();
	}
	return false;
	
}