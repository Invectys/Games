// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorGravityComponent.h"
#include "..\Public\MyActorGravityComponent.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "HasGravitation.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UMyActorGravityComponent::UMyActorGravityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	Radius = 200;
	Speed = 1;
	Delta = 0;

	
	// ...
}


// Called when the game starts
void UMyActorGravityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	if (CenterObject)
	{
		
		bool bHasGravityInterface = CenterObject->GetClass()->ImplementsInterface(UHasGravitation::StaticClass());
		if (bHasGravityInterface)
		{
			IHasGravitation* Gravity = Cast<IHasGravitation>(CenterObject);
			UMyActorGravityComponent* GravityComponent = Gravity->getGravityComponent();
			if (GravityComponent)
			{
				float AdditionSpeed = GravityComponent->getSpeed();
				Speed += AdditionSpeed;
			}
			else
			{
				UE_LOG(LogTemp,Error,TEXT("getGravityComponent() returned NULL ! Implement It"))
			}
			
		}
	}
	else
	{
		
	}
	

	
}

void UMyActorGravityComponent::UpdateLocation()
{
	if (Radius > 0)
	{
		FVector Center;
		if (CenterObject)
		{
			Center = CenterObject->GetActorLocation();
		}
		else
		{
			Center = GetOwner()->GetActorLocation() * FVector(0, 0, 1);
		}
		AActor* Owner = GetOwner();
		float GameTime = UKismetSystemLibrary::GetGameTimeInSeconds((UObject*)GetWorld());
		float argument = GameTime * Speed + Delta;
		float NewX = (FMath::Sin(argument) * Radius) + Center.X;
		float NewY = (FMath::Cos(argument) * Radius) + Center.Y;
		float NewZ = Center.Z;
		Owner->SetActorLocation(FVector(NewX, NewY, NewZ));
		UE_LOG(LogTemp, Display, TEXT("%f"), argument);
	}
	
	
}


// Called every frame
void UMyActorGravityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	UpdateLocation();
}

