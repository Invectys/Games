// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

//#include "Templates/SharedPointer.h"

#include "MyInventoryComponent.generated.h"

class AMyDrop;

USTRUCT(BlueprintType)
struct FSlotStruct {

	GENERATED_USTRUCT_BODY()

	FSlotStruct();

	UPROPERTY(BlueprintReadOnly)
		int32 Amount;
	UPROPERTY(BlueprintReadOnly)
		TSubclassOf<AMyDrop> Class;

	
	bool isEmpty();
	void setItem(TSubclassOf<AMyDrop> NewClass, int32 NewAmount = 1);
	

	
	

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEWARONLINE_API UMyInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
		bool AddItem(AMyDrop* Drop);
	UFUNCTION()
		bool AddItembyClass(TSubclassOf<AMyDrop> Class);

	UFUNCTION()
		void Drop(int SlotInd);

	

private: 
	UPROPERTY(Replicated)
		TArray<FSlotStruct> Slots;
	UPROPERTY()
		int32 MaxSlots;
	
public:
	UFUNCTION(BlueprintCallable,BlueprintPure)
		TArray<FSlotStruct>& getSlots() { return Slots; }
	

	UFUNCTION()
		void setSlots(TArray<FSlotStruct> NewSlots) { Slots = NewSlots; }
	UFUNCTION(BlueprintGetter)
		int getMaxSlotsCount() { return MaxSlots; }
};
