// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Switch"));
	LightSourceMesh = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightSource"));

	RootComponent = CollisionComponent;
	SwitchMesh->SetupAttachment(RootComponent);
	LightSourceMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!isLightOn)
	{
		LightSourceMesh->SetIntensity(0.0f);
	}
	else if (isLightOn)
	{
		LightSourceMesh->SetIntensity(5000.0f);
	}

}

void ALightSwitch::Use_Implementation()
{
	isLightOn = (isLightOn == true) ? false : true;
}

