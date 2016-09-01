// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "Coletavel.h"
#include "MyCharacter.h"


// Sets default values
AColetavel::AColetavel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &AColetavel::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AColetavel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColetavel::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AColetavel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetColeta(MyCharacter->GetColeta()+1);
		Destroy();

	}
}


void AColetavel::SetQntColeta(int Coletaveis) {
	QntColeta = Coletaveis;
}

int AColetavel::GetQntColeta() {
	return QntColeta;
}
