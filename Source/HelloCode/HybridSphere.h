// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HybridSphere.generated.h"


UCLASS(BlueprintType)
class HELLOCODE_API AHybridSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHybridSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = "Components", EditAnywhere)
		class USphereComponent* Sphere;
	UPROPERTY(Category = "Components", EditAnywhere,BlueprintReadWrite)
		class UStaticMeshComponent* Mesh;
	UPROPERTY(Category = "Components", EditAnywhere,BlueprintReadOnly)
		class UTextRenderComponent* Text;
	UPROPERTY(Category = "Components", EditAnywhere)
		class UParticleSystemComponent* Particles;

	
public:
	UFUNCTION(BlueprintNativeEvent)
	void MyOnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor); //공용 네임벨류로 남겨두는 것

	void MyOnBeginOverlap_Implementation(AActor* OverlappedActor, AActor* OtherActor);//BP에서 함수 오버라이드해서 쓸수 있도록함

	UFUNCTION(BlueprintNativeEvent)
	void MyOnEndOverlap(AActor* OverlappedActor, AActor* OtherActor); //공용 네임벨류로 남겨두는 것

	void MyOnEndOverlap_Implementation(AActor* OverlappedActor, AActor* OtherActor);//BP에서 함수 오버라이드해서 쓸수 있도록함


};
