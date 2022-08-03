// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" //�����Ҷ� �ּ����� ��ɸ� �־���� �������
#include "GameFramework/Actor.h" //��ӹޱ�
#include "HelloSphere.generated.h" //���� ������ ������� �־���Ѵ�

UCLASS()
class HELLOCODE_API AHelloSphere : public AActor //API �ȿ� ���� ����
{
	GENERATED_BODY() //Ŭ���� ������
	
public:	
	// Sets default values for this actor's properties
	AHelloSphere(); //������

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
