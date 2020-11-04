// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "HasGravitation.h"
#include "MyActorWithGravity.generated.h"

class UMyActorGravityComponent;

UCLASS()
class SPACEWARONLINE_API AMyActorWithGravity : public AMyActor,public IHasGravitation
{
	GENERATED_BODY()
public:

	AMyActorWithGravity(const FObjectInitializer& Initializer);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	virtual UMyActorGravityComponent* getGravityComponent() const override { return GravityComponent; }


	UPROPERTY(VisibleAnyWhere)
		class UMyActorGravityComponent* GravityComponent;

public:


};
