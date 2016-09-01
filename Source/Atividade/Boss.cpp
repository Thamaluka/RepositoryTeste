// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "Boss.h"


// Sets default values
ABoss::ABoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	RootComponent = Root;


	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

	Count = 0;
}

// Called when the game starts or when spawned
void ABoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoss::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector Inicio = GetActorLocation();
	FVector LocalizacaoAtual = GetActorLocation();

	if (Count >= 0 && Count<200) {
		LocalizacaoAtual.Y++;
	}
	else if (Count>=200 && Count<400) {
		LocalizacaoAtual.X++;
	}
	else if (Count>=400 && Count <900) {
		LocalizacaoAtual.Y++;
	}
	else if (Count >= 900 && Count <1100) {
		LocalizacaoAtual.X++;
	}
	else if (Count >= 1100 && Count <1800) {
		LocalizacaoAtual.Y--;
	}
	else if (Count >= 1800 && Count <2100) {
		LocalizacaoAtual.X--;
	}else{
		Count = 0;
		SetActorLocation(Inicio);
	}
	

	Count++;
	SetActorLocation(LocalizacaoAtual);


}

