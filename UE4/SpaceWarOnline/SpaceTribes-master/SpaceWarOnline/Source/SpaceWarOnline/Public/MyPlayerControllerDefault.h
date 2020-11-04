// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerControllerDefault.generated.h"

/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyPlayerControllerDefault : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerControllerDefault(const FObjectInitializer& Initializer);
	AMyPlayerControllerDefault();
protected:
private:
public:
	virtual void SetupInputComponent() override;
};
