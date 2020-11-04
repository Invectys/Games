// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawn.h"
#include "CanBeDestroyed.h"
#include "MyCanBeDestroyedPawn.generated.h"

class UMyCanBeDestroyedComponent;
/**
 * 
 */
UCLASS()
class SPACEWARONLINE_API AMyCanBeDestroyedPawn : public AMyPawn, public ICanBeDestroyed
{
	GENERATED_BODY()
public:
	AMyCanBeDestroyedPawn(const FObjectInitializer& Initializer);

public:

	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		AController* EventInstigator,
		AActor* DamageCauser
	) override;


private:
	UPROPERTY()
		UMyCanBeDestroyedComponent* MeDestroyerComponent;

public:
	
	UFUNCTION(BlueprintCallable,BlueprintPure)
		virtual UMyCanBeDestroyedComponent* getCanBeDestroyComponent() const override { return MeDestroyerComponent; }
};
