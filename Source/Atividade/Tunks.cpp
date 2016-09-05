// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "Tunks.h"
#include "ProjectileActor.h"
#include "MyCharacter.h"



// Sets default values
ATunks::ATunks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	RootComponent = Root;


	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

	Cont = 0;
	

}

// Called when the game starts or when spawned
void ATunks::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATunks::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (Cont > 100) {
		DropProjectile();
	}

	Cont++;
	
}


void ATunks::DropProjectile() {
	Cont = 0;
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

void ATunks::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AProjectileActor::StaticClass()))) {

		AProjectileActor* Projectile = Cast<AProjectileActor>(OtherActor);

	}
}