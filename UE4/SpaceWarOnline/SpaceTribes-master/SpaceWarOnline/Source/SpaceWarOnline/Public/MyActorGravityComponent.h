// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorGravityComponent.generated.h"

class AMyActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEWARONLINE_API UMyActorGravityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyActorGravityComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
private:

	 void UpdateLocation();


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	



	float getSpeed() { return Speed; }
	float getDelta() { return Delta; }
	float getRadius() { return Radius; }
	AMyActor* getCenterObject() { return CenterObject; }

private:

	UPROPERTY(EditAnyWhere)
		float Speed;
	UPROPERTY(EditAnyWhere)
		float Delta;
	UPROPERTY(EditAnyWhere)
		float Radius;
	UPROPERTY(EditAnyWhere)
		AMyActor* CenterObject;
	
};
