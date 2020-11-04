// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerControllerGame.h"
#include "GameFramework/Pawn.h"
#include "MyGameHUD.h"
#include "MyShip.h"

AMyPlayerControllerGame::AMyPlayerControllerGame(const FObjectInitializer& Initializer) : Super(Initializer)
{
	
}
void AMyPlayerControllerGame::BeginPlay()
{
	Super::BeginPlay();
	
	
}
void AMyPlayerControllerGame::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Inventory", EInputEvent::IE_Pressed, this, &AMyPlayerControllerGame::TryCallInventory);
}

void AMyPlayerControllerGame::BeginPlayingState()
{
	Super::BeginPlayingState();

	AddPawnWidget();
	
}

void AMyPlayerControllerGame::AddPawnWidget()
{
	UE_LOG(LogTemp, Log, TEXT("Adding pawn Widget"));
	APawn* OfPawn = GetPawn();
	AMyPawn* MyPawn = Cast<AMyPawn>(OfPawn);
	if (IsValid(MyPawn))
	{
		AMyGameHUD* HUD = getGameHUD();
		if (IsValid(HUD))
		{
			HUD->AddPawnWidget(MyPawn);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("cant add PawnWidget HUD is NUll"));
		}
		
		
	
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Posse on Pawn instead MyPawn!"))
	}
	
}

void AMyPlayerControllerGame::TryCallInventory()
{
	AMyGameHUD* HUD = getGameHUD();
	if (IsValid(GetPawn()))
	{
		if (IsValid(HUD))
		{
			bool has = HUD->isInventoryAdded();
			if (has)
			{
				HUD->RemoveInventoryWidget();
			}
			else
			{
				HUD->AddInventoryWidget(GetPawn());
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("cant add Inventory HUD is NUll"));
		}
		
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Eror add inventory : Pawn is NULL"));
	}
	
}