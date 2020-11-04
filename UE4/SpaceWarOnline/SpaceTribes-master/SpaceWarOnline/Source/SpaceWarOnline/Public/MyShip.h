// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCanBeDestroyedPawn.h"
#include "HasInventory.h"
#include "MyDropShipPartEngine.h"

#include "MyShip.generated.h"


struct FShipPartEngineStruct;
class UPaperSpriteComponent;
class UInputComponent;
class USphereComponent;
class UMyInventoryComponent;

UCLASS()
class SPACEWARONLINE_API AMyShip : public AMyCanBeDestroyedPawn, public IHasInventory
{
	GENERATED_BODY()
	
public: 
	AMyShip(const FObjectInitializer& Initializer);

protected:

private:

	void Throttle(float axis);
	void Turn(float axis);
	UFUNCTION(Server,WithValidation,reliable)
		void ThrottleServer(float axis);
	UFUNCTION(Server,WithValidation,reliable)
		void TurnServer(float axis);

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void RepairRotAndLoc();

	

	UFUNCTION(BlueprintAuthorityOnly)
		void UpdateMovement();
public:
	/** called when something enters the sphere component */
	UFUNCTION()
		void OnOverlapBegin(
			UPrimitiveComponent* CompOverlapped,
			AActor* OtherActor, 
			UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, 
			bool bFromSweep, 
			const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(
			UPrimitiveComponent* CompOverlapped,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);
	


private: 

	
	UPROPERTY(EditAnyWhere)
		UPaperSpriteComponent* ShipSprite;
	UPROPERTY()
		USphereComponent* Sphere;
	UPROPERTY()
		UMyInventoryComponent* Inventory;
	//Movement
	UPROPERTY(/*Replicated,*/meta=(ClampMin="-1",ClampMax="1"))
		float ThrottleAxis;
	UPROPERTY(/*Replicated,*/ meta = (ClampMin = "-1", ClampMax = "1"))
		float TurnAxis;

    UPROPERTY()
		FShipPartEngineStruct Engine;
		

public:
	UFUNCTION(BlueprintGetter)
		USphereComponent* getSphere() { return Sphere; }
	UFUNCTION(BlueprintGetter)
		virtual UMyInventoryComponent* getInventory() const override { return Inventory; }
	
	UFUNCTION(BlueprintGetter)
		UPaperSpriteComponent* getShipSprite() { return ShipSprite; }
	UFUNCTION(BlueprintGetter)
		FShipPartEngineStruct getEngine();
	UFUNCTION(BlueprintCallable)
		void setEngine(FShipPartEngineStruct NewEngine);
	
};




