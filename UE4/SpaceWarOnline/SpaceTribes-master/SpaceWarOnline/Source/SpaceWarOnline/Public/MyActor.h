// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

class UPaperSpriteComponent;

UCLASS()
class SPACEWARONLINE_API AMyActor : public AActor
{
	GENERATED_BODY()
	

public : 

	AMyActor(const FObjectInitializer& ObjectInitializer);
	AMyActor();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void RepairLocAndRot();

public:
	UPROPERTY(EditAnyWhere,BlueprintReadOnly)
		UPaperSpriteComponent* _Sprite;

public:
	UFUNCTION(BlueprintCallable,BlueprintPure)
		UPaperSpriteComponent* getSprite() { return _Sprite; }
};
