// Fill out your copyright notice in the Description page of Project Settings.


#include "MyShip.h"
#include "..\Public\MyShip.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "UnrealNetwork.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SphereComponent.h"
#include "MyInventoryComponent.h"
#include "MyPawnWidget.h"
#include "TimerManager.h"
//#include "MyDropShipPartEngine.h"

AMyShip::AMyShip(const FObjectInitializer& Initializer) : Super(Initializer)
{
	bReplicates = true;
	bReplicateMovement = true;
	

	ShipSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Ship Sprite"));
	ShipSprite->SetSimulatePhysics(true);
	ShipSprite->SetMassOverrideInKg(NAME_None,20);
	ShipSprite->SetLinearDamping(1);
	ShipSprite->SetAngularDamping(2);

	RootComponent = ShipSprite;
	SpringArm->SetupAttachment(RootComponent);
	
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->InitSphereRadius(200);
	Sphere->SetupAttachment(RootComponent);
	Sphere->bHiddenInGame = false;
	Sphere->SetGenerateOverlapEvents(true);

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AMyShip::OnOverlapBegin);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AMyShip::OnOverlapEnd);

	Inventory = CreateDefaultSubobject<UMyInventoryComponent>(TEXT("Inventory"));

	static ConstructorHelpers::FObjectFinder<UPaperSprite> AssetShip(TEXT("PaperSprite'/Game/Grafic/Sprites/Ships/enemyBlack1_Sprite.enemyBlack1_Sprite'"));
	ShipSprite->SetSprite(AssetShip.Object);

	static	ConstructorHelpers::FClassFinder<UMyPawnWidget> Widget(TEXT("/Game/Grafic/Widjets/Game/Process/MyPawnShipWidgetBP"));
	PawnWidgetClass = Widget.Class;

	//Movement
	ThrottleAxis = 0;
	TurnAxis = 0;
	RepairRotAndLoc();


	
	
}

void AMyShip::Throttle(float axis)
{
	
	//UE_LOG(LogTemp, Log, TEXT("Throttle"));
	if (ThrottleAxis != axis)
	{
		ThrottleAxis = axis;
		ThrottleServer(axis);
	}
	
}

void AMyShip::Turn(float axis)
{
	if (axis != TurnAxis)
	{
		TurnAxis = axis;
		TurnServer(axis);
	}
	
	//UE_LOG(LogTemp, Log, TEXT("Turn"));
	
}



void AMyShip::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	RepairRotAndLoc();
}

void AMyShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyShip::RepairRotAndLoc()
{
	float Yaw = GetActorRotation().Yaw;
	SetActorRotation(FRotator(0, Yaw, -90));
	SetActorLocation(GetActorLocation() * FVector(1, 1, 0));
	//UE_LOG(LogTemp, Log, TEXT("Repair"));
}

void AMyShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//UE_LOG(LogTemp, Log, TEXT("tick"));
	//UE_LOG(LogTemp, Log, TEXT("Has %s"), HasAuthority() ? TEXT("True") : TEXT("False"));
	if (HasAuthority())
	{
		UpdateMovement();
	}
	
	
	
}
void AMyShip::UpdateMovement()
{
	UPaperSpriteComponent* Sprite = getShipSprite();
	//Turn 
	if (TurnAxis != 0)
	{
		ShipSprite->AddTorqueInRadians(FVector(0,0, TurnAxis * getEngine().TurnTorque));
		//UE_LOG(LogTemp, Log, TEXT("Rotate %f"), getEngine().TurnTorque);
	}
	

	//Movement
	if (ThrottleAxis == 1)
	{
		float Strenght = getEngine().Throttle;
		FVector Force = -1 * Sprite->GetUpVector() * Strenght;
		Sprite->AddForce(Force);
		//UE_LOG(LogTemp, Log, TEXT("th %f"), getEngine().Throttle);
	}
}
void AMyShip::OnOverlapBegin(
	UPrimitiveComponent* CompOverlapped,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	AMyDrop* Drop = Cast<AMyDrop>(OtherActor);
	if (IsValid(Drop))
	{
		
		if (HasAuthority())
		{
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle,
				FTimerDelegate::CreateUObject(this, &IHasInventory::PickUpDrop, Drop), 0.2f, false);
		}
		else 
		{
			PickUpDrop(Drop);
		}
		
		
	}
	
	
}
void AMyShip::OnOverlapEnd(
	UPrimitiveComponent* CompOverlapped,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
}
void AMyShip::SetupPlayerInputComponent(UInputComponent* InputComponent) 
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("Throttle",this,&AMyShip::Throttle);
	InputComponent->BindAxis("Turn", this, &AMyShip::Turn);
}



void AMyShip::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	/*DOREPLIFETIME(AMyShip, TurnAxis);
	DOREPLIFETIME(AMyShip, ThrottleAxis);*/

}



void AMyShip::ThrottleServer_Implementation(float axis)
{
	//UE_LOG(LogTemp, Log, TEXT("-- %f"), axis);
	ThrottleAxis = axis;
}
bool AMyShip::ThrottleServer_Validate(float axis)
{
	return (axis <= 1) && (axis >= -1);
}

void AMyShip::TurnServer_Implementation(float axis)
{
	//UE_LOG(LogTemp, Log, TEXT("-- %f"), axis);
	TurnAxis = axis;
}
bool AMyShip::TurnServer_Validate(float axis)
{
	return (axis <= 1) && (axis >= -1);
}



void AMyShip::setEngine(FShipPartEngineStruct NewEngine)
{
	Engine = NewEngine;
}
FShipPartEngineStruct AMyShip::getEngine() {
	return Engine;
}
