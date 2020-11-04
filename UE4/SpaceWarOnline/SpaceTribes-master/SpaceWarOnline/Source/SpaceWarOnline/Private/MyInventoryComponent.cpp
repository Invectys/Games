// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryComponent.h"
#include "MyDrop.h"
#include "UnrealNetwork.h"


// Sets default values for this component's properties
UMyInventoryComponent::UMyInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bReplicates = false;
	PrimaryComponentTick.bCanEverTick = true;
	MaxSlots = 4;
	Slots.AddDefaulted(MaxSlots);
	
	
}


// Called when the game starts
void UMyInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UMyInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Log, TEXT("size %f"), Slots.Num());
	// ...
}
void UMyInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(UMyInventoryComponent, Slots, COND_OwnerOnly);
}
bool  UMyInventoryComponent::AddItembyClass(TSubclassOf<AMyDrop> _Class)
{
	UE_LOG(LogTemp, Log, TEXT("AddItem"));
	TSubclassOf<AMyDrop> Class = _Class;
	FDropInfoStruct Info = _Class.GetDefaultObject()->getDropInfo();
	TArray<FSlotStruct>& Slots = getSlots();

	bool bAdded = false;
	if (Info.CanStack)
	{
		for (FSlotStruct& slot : Slots)
		{
			if (!slot.isEmpty())
			{
				bool Cond = (slot.Class == Class) && (Info.StackMax > slot.Amount);
				if (Cond)
				{
					slot.Amount++;
					bAdded = true;
					break;
				}
				else
				{

				}
			}
			else
			{

			}

		}


	}
	else
	{
	}


	if (!bAdded) {
		for (FSlotStruct& slot : Slots)
		{
			if (slot.isEmpty())
			{
				slot.setItem(Class);
				bAdded = true;
				break;
			}
		}
	}

	return bAdded;
}
bool  UMyInventoryComponent::AddItem(AMyDrop* Drop)
{
	return AddItembyClass(Drop->GetClass());
	
	
}

void UMyInventoryComponent::Drop(int SlotInd)
{

}





void FSlotStruct::setItem(TSubclassOf<AMyDrop> NewClass, int32 NewAmount)
{
	Amount = NewAmount;
	Class = NewClass;
}

FSlotStruct::FSlotStruct()
{
	Amount = 0;
	Class = NULL;
}

bool FSlotStruct::isEmpty()
{
	return Class == NULL;
}