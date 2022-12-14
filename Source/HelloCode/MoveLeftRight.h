// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveLeftRight.generated.h"

UENUM(BlueprintType)
enum class EMoveRL : uint8
{
	RL_Right UMETA(DisplayName = "Right"),
	RL_Left UMETA(DisplayName = "Left"),
};

UCLASS()
class HELLOCODE_API AMoveLeftRight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveLeftRight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) //BP에서도 편집가능
	class USceneComponent* Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh;

	EMoveRL MoveRL;
};
