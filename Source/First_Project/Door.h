// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "UseableInterface.h"
#include "Door.generated.h"

UCLASS()
class FIRST_PROJECT_API ADoor : public AActor, public IUseableInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FrameMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;

	bool doorToggle;
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Use_Implementation() override;

};
