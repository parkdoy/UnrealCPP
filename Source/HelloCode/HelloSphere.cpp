// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloSphere.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AHelloSphere::AHelloSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//��ü �ݸ��� ����
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//SphereComponent�� ��Ʈ������Ʈ�� �����
	RootComponent = SphereComponent;
	//������ ����
	SphereComponent->InitSphereRadius(220.0f);
	//�ݸ��� ������ ����
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	
	//StaticMeshComponent�� SphereVisual ����
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	//SphereVisual�� ��Ʈ ������Ʈ�� ���δ�.
	SphereVisual->AttachTo(RootComponent);
	//ShapeSphere ������ ã�Ƽ� SphereAsset�� �ִ´�
	ConstructorHelpers::FObjectFinder<UStaticMesh>SphereAssest(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	
	//SphereVisual�� ��Ƽ���� ����
	ConstructorHelpers::FObjectFinder<UMaterial>SphereMaterial(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));

	if (SphereAssest.Succeeded())
	{
		//���� ����
		SphereVisual->SetStaticMesh(SphereAssest.Object);
		//
		SphereVisual->SetMaterial(0, SphereMaterial.Object);
		//��ġ�� ����
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -50.0f));

	}

	//UParticleSystemComponent�� FireParticles ����
	UParticleSystemComponent* FireParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));
	//FireParticles�� SphereVisual�� ���δ�.
	FireParticles->AttachTo(SphereVisual);
	//�����Ҷ� �ڵ����� Ȱ��ȭ ��Ų��
	FireParticles->bAutoActivate = true;

	//P_Fire ������ ã�Ƽ� FireVisual�� �ִ´�.
	ConstructorHelpers::FObjectFinder<UParticleSystem>FireVisual(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (FireVisual.Succeeded())
	{
		//FireParticles�� FireVisual ������ �����Ų��.
		FireParticles->SetTemplate(FireVisual.Object);
	}


	//HelloSphere�� ������ protected �� ������Ʈ ���
	//UTextRenderComponent���� TextRenderComponent ����
	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));

	//TextRenderComponent�� SphereVisual�� ���δ�.
	TextRenderComponent->AttachTo(SphereVisual);

	//TextRenderComponent�� ��ġ ����
	TextRenderComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 110.0f));
	//�߾� ���Ľ�Ŵ
	TextRenderComponent->SetHorizontalAlignment(EHTA_Center);

	//TextRenderComponent�� ũ�� ����
	TextRenderComponent->SetYScale(2.0f);
	TextRenderComponent->SetXScale(2.0f);

	//TextRenderComponent�� Visibility ����
	TextRenderComponent->SetVisibility(true);
	
	//TextRenderComponent�� �ؽ�Ʈ ����
	//(NSLOCTEXT ��ũ�θ� ���ؼ� AnyNs ���ӽ����̽��� AnyŰ�� HelloWorld �ؽ�Ʈ ����
	TextRenderComponent->SetText(NSLOCTEXT("AnyNs", "Any", "HelloWorld"));
	
	//���ε�
	OnActorBeginOverlap.AddDynamic(this, &AHelloSphere::MyOnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AHelloSphere::MyOnEndOverlap);

}

// Called when the game starts or when spawned
void AHelloSphere::BeginPlay()
{

	Super::BeginPlay();//�θ��� �����θ� ����
	
}

// Called every frame
void AHelloSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHelloSphere::MyOnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	FString outputString;
	outputString = "Hello" + OtherActor->GetName() + "!";
	TextRenderComponent -> SetText(FText::FromString(outputString));

}
void AHelloSphere::MyOnEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	TextRenderComponent->SetText(NSLOCTEXT("AnyNs", "Any", "HelloWorld"));
}
;