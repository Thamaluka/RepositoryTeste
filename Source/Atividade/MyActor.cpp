// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "MyActor.h"



// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	RootComponent = Root;
	

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

	Cont = 0;
	MovimentacaoL = false;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector LocalizacaoAtual = GetActorLocation();
	
	if (!MovimentacaoL) {
		if (Cont >= 0 && Cont<50) {
			LocalizacaoAtual.Y++;
		}
		else if (Cont >= 50 && Cont<100) {
			LocalizacaoAtual.X--;
		}
		else if (Cont >= 100 && Cont<150) {
			LocalizacaoAtual.Y--;
		}
		else if (Cont >= 150 && Cont<201) {
			LocalizacaoAtual.X++;
		}
		else
		{
			Cont = 0;
		}
	}
	else{
		if (Cont >= 0 && Cont<100) {
			LocalizacaoAtual.X--;
		}
		else if (Cont >= 100 && Cont<200) {
			LocalizacaoAtual.Y--;
		}
		else if (Cont >= 200 && Cont<300) {
			LocalizacaoAtual.Y++;
		}
		else if (Cont >= 300 && Cont<401) {
			LocalizacaoAtual.X++;
		}
		else
		{
			Cont = 0;
		}
	}

	Cont++;
	SetActorLocation(LocalizacaoAtual);
}



