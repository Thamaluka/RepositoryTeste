// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "Boss.h"
#include "MyCharacter.h"
#include "ProjectileActor.h"


// Sets default values
ABoss::ABoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->OnComponentBeginOverlap.AddDynamic(this, &ABoss::OnOverlapBegin);
	RootComponent = Root;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

	FVector Inicio = GetActorLocation();

	BossLife = 10;
	Count = 0;
	BossLife = 10;
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
	FVector LocalizacaoAtual = GetActorLocation();
	FString HP= FString::Printf(TEXT("Life: %d"),GetBossLife());
	

	if (Count >= 0 && Count<200) {
		LocalizacaoAtual.Y++;
	}
	else if (Count>=200 && Count<400) {
		LocalizacaoAtual.X++;
	}
	else if (Count>=400 && Count <900) {
		LocalizacaoAtual.Y++;
	}
	else if (Count >= 900 && Count <1200) {
		LocalizacaoAtual.X++;
	}
	else if (Count >= 1200 && Count <1900) {
		LocalizacaoAtual.Y--;
	}
	else if (Count >= 1900 && Count <2400) {
		LocalizacaoAtual.X--;
	}else{
		Count = 0;
		SetActorLocation(Inicio);
	}
	

	Count++;
	SetActorLocation(LocalizacaoAtual);

}


void ABoss::SetBossLife(int NewLife) {
	BossLife = NewLife;
}

int ABoss::GetBossLife() {
	if (BossLife > 10) {
		Destroy();
	}
	return BossLife;
}

void ABoss::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetLife(0);
		
	}


	//Colisao do Boss com o tiro
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AProjectileActor::StaticClass()))) {
		
		AProjectileActor* Projectile = Cast<AProjectileActor>(OtherActor);

		SetBossLife(GetBossLife() - 1);
	}
}


void ABoss::DropProjectile() {
	FActorSpawnParameters SpawnParameters;
	UWorld* World = GetWorld();
	if (World != nullptr) {
		FRotator Rotation = MeshComp->GetComponentRotation();
		AProjectileActor* Proj = World->SpawnActor<AProjectileActor>
			(GetActorLocation(), Rotation,
				SpawnParameters);
		if (Proj != nullptr) {
			UE_LOG(LogTemp, Warning, TEXT("Spawn OK!"));
		}
	}
}
