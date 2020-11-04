// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Blueprint/UserWidget.h"
#include "MyPawnWidget.h"
#include "ConstructorHelpers.h"
// Sets default values

AMyPawn::AMyPawn(const FObjectInitializer& Initializer) : Super(Initializer)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	Camera->SetupAttachment(SpringArm);
	RootComponent = SpringArm;
	SpringArm->bDoCollisionTest = false;
	SpringArm->TargetArmLength = 400;
	SpringArm->SetWorldRotation(FRotator(-90, 0, 0));
	SpringArm->bAbsoluteRotation = true;



	
}
AMyPawn::AMyPawn()
{

}
// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

