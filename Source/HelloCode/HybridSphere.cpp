// Fill out your copyright notice in the Description page of Project Settings.


#include "HybridSphere.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/TextRenderComponent.h"



// Sets default values
AHybridSphere::AHybridSphere()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapSphere"));
	RootComponent = Sphere;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(Sphere);

	Particles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particles"));
	Particles->AttachTo(Mesh);

	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
	Text->AttachTo(Mesh);

	//내가 만든 함수에 바인드 OnActorBeginOverlap
	//바인드 걸어줄때는 임플리먼트 함수가 아니라 공용함수 네임을 사용한다.
	OnActorBeginOverlap.AddDynamic(this, &AHybridSphere::MyOnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AHybridSphere::MyOnEndOverlap);

}

// Called when the game starts or when spawned
void AHybridSphere::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHybridSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHybridSphere::MyOnBeginOverlap_Implementation(AActor* OverlappedActor, AActor* OtherActor)
{
	FString outputString;
	outputString = "Hello From C++!";
	Text->SetText(FText::FromString(outputString));

}

void AHybridSphere::MyOnEndOverlap_Implementation(AActor* OverlappedActor, AActor* OtherActor)
{
	Text->SetText(NSLOCTEXT("AnyNS", "Any", "Goodbye Form C++"));
}

