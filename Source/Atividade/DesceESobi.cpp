// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "DesceESobi.h"


// Sets default values
ADesceESobi::ADesceESobi()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ADesceESobi::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADesceESobi::Tick( float DeltaTime )
{

	if (!side) {
		Super::Tick(DeltaTime);
		FVector LocalizacaoAtual = GetActorLocation();
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
		LocalizacaoAtual.X -= DeltaHeight * 550.0f;
		RunningTime += DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}
	else {

	}
	
}

