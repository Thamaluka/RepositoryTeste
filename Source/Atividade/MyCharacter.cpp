// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "MyCharacter.h"
#include "ProjectileActor.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->bGenerateOverlapEvents = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(GetCapsuleComponent());

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	PlayerCamera->AttachTo(CameraBoom);

	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComp"));
	ArrowComp->SetHiddenInGame(false);
	ArrowComp->ArrowSize = 2.0f;
	ArrowComp->AttachTo(MeshComp);

	GetCharacterMovement()->MaxWalkSpeed = 400;
	

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	Tiro = false;

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMyCharacter::Turn);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	InputComponent->BindAction("Run", IE_Pressed, this, &AMyCharacter::StartRun);
	InputComponent->BindAction("Run", IE_Released, this, &AMyCharacter::StopRun);

	InputComponent->BindAction("Drop", IE_Pressed, this, &AMyCharacter::DropProjectile);
	
	
}


void AMyCharacter::MoveForward(float Value) {
	FVector Forward(1, 0, 0);
	AddMovementInput(Forward, Value);
}

void AMyCharacter::MoveRight(float Value) {
		FVector Right(0, 1, 0);
		AddMovementInput(Right, Value);
		
}

void AMyCharacter::StartRun() {
	GetCharacterMovement()->MaxWalkSpeed = 800;
}

void AMyCharacter::StopRun() {
	GetCharacterMovement()->MaxWalkSpeed = 400;
}


void AMyCharacter::SetLife(int NewLife) {
	Life = NewLife;
}

int AMyCharacter::GetLife() {
	return Life;
}


void AMyCharacter::SetColeta(int NewColeta) {
	Coleta = NewColeta;
}

int AMyCharacter::GetColeta() {
	if (Coleta==10)
	{
		AbleAtack = true;
	}
	return Coleta;
}

bool AMyCharacter::GetAbleAtack() {
	return AbleAtack;
}

void AMyCharacter::SetAbleAtack(bool Able) {
	AbleAtack = Able;

}


void AMyCharacter::SetTiro(bool Bala) {
	Tiro = Bala;
}

bool AMyCharacter::GetTiro() {
	return Tiro;
}



void AMyCharacter::OnDeath() {
	if (Life == 0) {
		FVector InitialLocation(-440.0f, -20.0f, 107.0f);
		Life = 3;
		SetActorLocation(InitialLocation);
	}
}

void AMyCharacter::DropProjectile() {
	Tiro = true;
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

void AMyCharacter::Turn(float Value) {
	//AddControllerYawInput(Value);
	FRotator NewRotation = ArrowComp->GetComponentRotation();
	NewRotation.Yaw += Value;
	ArrowComp->SetWorldRotation(NewRotation);
	
}
