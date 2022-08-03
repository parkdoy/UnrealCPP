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

	//구체 콜리전 생성
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//SphereComponent를 루트컴포넌트로 만든다
	RootComponent = SphereComponent;
	//반지름 설정
	SphereComponent->InitSphereRadius(220.0f);
	//콜리전 프리셋 지정
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	
	//StaticMeshComponent로 SphereVisual 생성
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	//SphereVisual를 루트 컴포넌트에 붙인다.
	SphereVisual->AttachTo(RootComponent);
	//ShapeSphere 에셋을 찾아서 SphereAsset에 넣는다
	ConstructorHelpers::FObjectFinder<UStaticMesh>SphereAssest(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	
	//SphereVisual에 머티리얼 적용
	ConstructorHelpers::FObjectFinder<UMaterial>SphereMaterial(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));

	if (SphereAssest.Succeeded())
	{
		//에셋 적용
		SphereVisual->SetStaticMesh(SphereAssest.Object);
		//
		SphereVisual->SetMaterial(0, SphereMaterial.Object);
		//위치값 적용
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -50.0f));

	}

	//UParticleSystemComponent로 FireParticles 생성
	UParticleSystemComponent* FireParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));
	//FireParticles을 SphereVisual에 붙인다.
	FireParticles->AttachTo(SphereVisual);
	//시작할때 자동으로 활성화 시킨다
	FireParticles->bAutoActivate = true;

	//P_Fire 에셋을 찾아서 FireVisual에 넣는다.
	ConstructorHelpers::FObjectFinder<UParticleSystem>FireVisual(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (FireVisual.Succeeded())
	{
		//FireParticles에 FireVisual 에셋을 적용시킨다.
		FireParticles->SetTemplate(FireVisual.Object);
	}


	//HelloSphere에 만들어둔 protected 된 컴포넌트 사용
	//UTextRenderComponent형의 TextRenderComponent 생성
	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));

	//TextRenderComponent를 SphereVisual에 붙인다.
	TextRenderComponent->AttachTo(SphereVisual);

	//TextRenderComponent의 위치 설정
	TextRenderComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 110.0f));
	//중앙 정렬시킴
	TextRenderComponent->SetHorizontalAlignment(EHTA_Center);

	//TextRenderComponent의 크기 설정
	TextRenderComponent->SetYScale(2.0f);
	TextRenderComponent->SetXScale(2.0f);

	//TextRenderComponent의 Visibility 설정
	TextRenderComponent->SetVisibility(true);
	
	//TextRenderComponent에 텍스트 적용
	//(NSLOCTEXT 메크로를 통해서 AnyNs 네임스페이스에 Any키에 HelloWorld 텍스트 지정
	TextRenderComponent->SetText(NSLOCTEXT("AnyNs", "Any", "HelloWorld"));
	
	//바인딩
	OnActorBeginOverlap.AddDynamic(this, &AHelloSphere::MyOnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AHelloSphere::MyOnEndOverlap);

}

// Called when the game starts or when spawned
void AHelloSphere::BeginPlay()
{

	Super::BeginPlay();//부모의 구현부를 실행
	
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