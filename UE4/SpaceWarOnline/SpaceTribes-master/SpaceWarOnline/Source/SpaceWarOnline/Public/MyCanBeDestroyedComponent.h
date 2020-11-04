// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyCanBeDestroyedComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEWARONLINE_API UMyCanBeDestroyedComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyCanBeDestroyedComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(BlueprintReadOnly)
		float _Health;
	UPROPERTY(BlueprintReadOnly)
		float _MaxHealth;
	UPROPERTY(BlueprintreadOnly)
		float _Armor;
	UPROPERTY(BlueprintreadOnly)
		float _MaxArmor;
	
public:
	
};
