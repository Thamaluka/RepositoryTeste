// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "SobiEDesce.h"
#include "MyCharacter.h"
#include "ProjectileActor.h"

// Sets default values
ASobiEDesce::ASobiEDesce()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->OnComponentBeginOverlap.AddDynamic(this, &ASobiEDesce::OnOverlapBegin);
	RootComponent = Root;
	side = 0;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ASobiEDesce::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASobiEDesce::Tick( float DeltaTime )
{
	
	Super::Tick( DeltaTime );
	FVector LocalizacaoAtual = GetActorLocation();
	if (side==1) {
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
		LocalizacaoAtual.Z += DeltaHeight * 100.0f;
		RunningTime += DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}
	else if (side == 2) {
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
		LocalizacaoAtual.X -= DeltaHeight * 200.0f;
		RunningTime += DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}
	else {
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
		LocalizacaoAtual.Y -= DeltaHeight * 200.0f;
		RunningTime += DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}

}

void ASobiEDesce::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetLife(MyCharacter->GetLife() - DamageAmount);
		MyCharacter->OnDeath();
	}

	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AProjectileActor::StaticClass()))) {

		AProjectileActor* Projectile = Cast<AProjectileActor>(OtherActor);
		Destroy();
	}

}


