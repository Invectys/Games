// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayerControllerDefault.h"
#include "MyPlayerControllerGame.generated.h"

class APawn;
class AMyGameHUD;
/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyPlayerControllerGame : public AMyPlayerControllerDefault
{
	GENERATED_BODY()

public:
	AMyPlayerControllerGame(const FObjectInitializer& Initializer);
protected:

private:
	
	UFUNCTION(BlueprintCosmetic,BlueprintCallable)
	void TryCallInventory();
public:
	virtual void SetupInputComponent() override;

	virtual void BeginPlayingState() override;
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCosmetic)
		void AddPawnWidget();


private:
	


public:
	AMyGameHUD* getGameHUD() { return  Cast<AMyGameHUD>(GetHUD()); };
	
};
