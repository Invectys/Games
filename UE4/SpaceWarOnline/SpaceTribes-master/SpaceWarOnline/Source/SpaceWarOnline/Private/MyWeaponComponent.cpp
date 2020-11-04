// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeaponComponent.h"

// Sets default values for this component's properties
UMyWeaponComponent::UMyWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	ShootForce = 10000;
	// ...
}


// Called when the game starts
void UMyWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyWeaponComponent::Shoot()
{
}

