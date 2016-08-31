// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class ATIVIDADE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartRun();
	void StopRun();
	

	void SetColeta(bool NewColeta);
	bool GetColeta();

	void SetLife(int NewLife);
	int GetLife();
	void OnDeath();

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere)
		UArrowComponent* ArrowComp;
	UPROPERTY(EditAnywhere)
		int Life = 3;

	bool Coleta;
	void DropProjectile();
	void Turn(float Value);
	

	

	
	
};
