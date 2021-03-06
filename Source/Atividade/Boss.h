// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Boss.generated.h"

UCLASS()
class ATIVIDADE_API ABoss : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoss();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void SetBossLife(int NewLife);
	int GetBossLife();

private:
	UPROPERTY(EditAnywhere)
		UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		float DamageAmount = 1;

	int Count;
	int BossLife;
	FVector Inicio;
	void DropProjectile();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
};
