// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" //빌드할때 최소한의 기능만 넣어놓은 헤더파일
#include "GameFramework/Actor.h" //상속받기
#include "HelloSphere.generated.h" //가장 마지막 헤더선언에 있어야한다

UCLASS()
class HELLOCODE_API AHelloSphere : public AActor //API 안에 액터 생성
{
	GENERATED_BODY() //클래스 생성됨
	
public:	
	// Sets default values for this actor's properties
	AHelloSphere(); //생성자

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	class UTextRenderComponent* TextRenderComponent;

	UFUNCTION()
		void MyOnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
		void MyOnEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
