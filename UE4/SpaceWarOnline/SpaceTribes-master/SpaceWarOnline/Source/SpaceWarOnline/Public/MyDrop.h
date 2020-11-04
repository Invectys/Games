// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "MyDrop.generated.h"


USTRUCT(BlueprintType)
struct FDropInfoStruct {
	GENERATED_USTRUCT_BODY()

    FDropInfoStruct() {
		CanStack = true;
		StackMax = 64;
	}
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FString Name;
	UPROPERTY(EditAnyWhere,BlueprintReadWrite)
		FString Description;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool CanStack;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int32 StackMax;


};

/**
 * 
 */
UCLASS(Abstract)
class SPACEWARONLINE_API AMyDrop : public AMyActor
{
	GENERATED_BODY()
	
public:
	AMyDrop(const FObjectInitializer& Initializer);
	
protected:

private:

public:
	UFUNCTION()
		virtual bool Use() { return false; };
	


public:
	UPROPERTY(BlueprintReadOnly)
	FDropInfoStruct _DropInfo;
public:
	UFUNCTION(BlueprintGetter)
	FDropInfoStruct getDropInfo()
	{
		return _DropInfo;
	}


};
