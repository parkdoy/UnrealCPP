// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveRect.generated.h"

UENUM(BlueprintType)
enum class EMoveRect : uint8
{
	Rect_Right UMETA(DisplayName = "Right"),
	Rect_Left UMETA(DisplayName = "Left"),
	Rect_Up UMETA(DisplayName = "Up"),
	Rect_Down UMETA(DisplayName = "Down"),
};

UCLASS()
class HELLOCODE_API AMoveRect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveRect();

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

	EMoveRect MoveRect;
};
