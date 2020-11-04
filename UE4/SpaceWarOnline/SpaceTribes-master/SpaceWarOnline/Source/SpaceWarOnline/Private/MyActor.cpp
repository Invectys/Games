// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "PaperSpriteComponent.h"

// Sets default values
AMyActor::AMyActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Ship Sprite"));
	RootComponent = (USceneComponent*)getSprite();
	
	RepairLocAndRot();
}

AMyActor::AMyActor()
{
	
}



// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	RepairLocAndRot();
}

void AMyActor::RepairLocAndRot()
{
	float Yaw = GetActorRotation().Yaw;
	SetActorRotation(FRotator(0, Yaw, -90));
	SetActorLocation(GetActorLocation() * FVector(1, 1, 0));
}

