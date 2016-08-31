// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "MyHUD.h"
#include "Engine/Font.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "Coletavel.h"


AMyHUD::AMyHUD() {
	static ConstructorHelpers::FObjectFinder<UFont>
		Font(TEXT("Font'/Engine/EngineFonts/TinyFont.TinyFont'"));
	
	if (Font.Succeeded()) {
		HUDFont = Font.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D>
		Texture(TEXT("Texture2D'/Game/StarterContent/Textures/vidas.vidas'"));
	if (Texture.Succeeded()) {
		MyTexture = Texture.Object;
	}


}

void AMyHUD::DrawHUD() {
	Super::DrawHUD();

	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX,Canvas->SizeY);
	
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	AColetavel* Coletavel = Cast<AColetavel>(UGameplayStatics::GetPlayerPawn(this,0));

	FString LifeString = FString::Printf(TEXT("Life: %d"),MyCharacter->GetLife());
	FString Coletaveis = FString::Printf(TEXT("Coletaveis: %d"), Coletavel->GetQntColeta());


	//Vidas Personagem

	int LifeChar = MyCharacter->GetLife();
	
	if (LifeChar == 3) {
		DrawTextureSimple(MyTexture, 50, 50, 0.3f, false);
		DrawTextureSimple(MyTexture, 80, 50, 0.3f, false);
		DrawTextureSimple(MyTexture, 110, 50, 0.3f, false);
	}

	if (LifeChar == 2){
		 DrawTextureSimple(MyTexture, 50, 50, 0.3f, false);
		 DrawTextureSimple(MyTexture, 80, 50, 0.3f, false);
	} 

	if(LifeChar == 1){
		 DrawTextureSimple(MyTexture, 50, 50, 0.3f, false);
	 }	



	

	/*
	DrawTexture(MyTexture, 400, 50, MyCharacter->GetLife(),
	MyTexture->GetSizeY(), 200, 200, MyCharacter->GetLife(),
	MyTexture->GetSizeY(), FLinearColor::White,
	EBlendMode::BLEND_Opaque, 1.0f, false, 0.0f, FVector2D::ZeroVector);
	*/
	
	//DrawText(LifeString, FColor::Black, 50, 50, HUDFont);
	//DrawText(Coletaveis, FColor::Black, 50, 50, HUDFont);

	

}

