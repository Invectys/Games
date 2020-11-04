// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "MyActorWithGravity.h"
#include "MyPlanetDefault.generated.h"
/**
 * 
 */
class UMyActorGravityComponent;



UCLASS()
class SPACEWARONLINE_API AMyPlanetDefault : public AMyActorWithGravity
{
	GENERATED_BODY()
	
public:
	
	AMyPlanetDefault(const FObjectInitializer& Initializer);
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	

public:
	


	
	



			
};
