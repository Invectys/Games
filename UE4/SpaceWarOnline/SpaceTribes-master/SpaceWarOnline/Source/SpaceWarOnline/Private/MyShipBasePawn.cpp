// Fill out your copyright notice in the Description page of Project Settings.


#include "MyShipBasePawn.h"
#include "ConstructorHelpers.h"
#include "MyShipBasePawnWidget.h"

AMyShipBasePawn::AMyShipBasePawn(const FObjectInitializer& Initializer) : Super(Initializer)
{
	static	ConstructorHelpers::FClassFinder<UMyShipBasePawnWidget> Widget(TEXT("/Game/Grafic/Widjets/Game/Process/MyShipBasePawnWidgetBP"));
	PawnWidgetClass = Widget.Class;
}