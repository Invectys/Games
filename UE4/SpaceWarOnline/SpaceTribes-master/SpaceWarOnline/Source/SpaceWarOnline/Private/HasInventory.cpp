// Fill out your copyright notice in the Description page of Project Settings.


#include "HasInventory.h"
#include "MyInventoryComponent.h"
#include "MyDrop.h"

// Add default functionality here for any IHasInventory functions that are not pure virtual.
UMyInventoryComponent* IHasInventory::getInventory() const
{
	return NULL;
}

void IHasInventory::PickUpDrop(AMyDrop* Drop) const
{
	if (!IsValid(getInventory()))
	{
		UE_LOG(LogTemp, Error, TEXT("Inventory Invalid  Cant Pick up Item !  Override getInventory() function"));
	}
	if (IsValid(Drop))
	{
		bool result = getInventory()->AddItem(Drop);
		if (result)
		{
			Drop->Destroy();
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Pick Up Abborted"));
	}
	
}
