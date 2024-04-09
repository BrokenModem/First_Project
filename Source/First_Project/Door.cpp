// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	FrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));

	RootComponent = CollisionComponent;
	FrameMesh->SetupAttachment(RootComponent);
	DoorMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float newRotation;

	if (!doorToggle)
	{
		newRotation = 0.0f;
	}
	else if (doorToggle)
	{
		newRotation = -90.0f;
	}

	FRotator newLocation = DoorMesh->GetRelativeRotation();

	newLocation.Yaw = newRotation;

	DoorMesh->SetRelativeRotation(newLocation);

}

void ADoor::Use_Implementation()
{
	doorToggle = (doorToggle == true) ? false : true;
}

