// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeaponLaserGunComponent.h"


FWeaponLaserGunStruct UMyWeaponLaserGunComponent::getInfo()
{
	return Info;
}

void UMyWeaponLaserGunComponent::Shoot()
{
	Super::Shoot();
}
