// Fill out your copyright notice in the Description page of Project Settings.

#include "Atividade.h"
#include "MyHUD.h"
#include "Engine/Font.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"


AMyHUD::AMyHUD() {
	static ConstructorHelpers::FObjectFinder<UFont>
		Font(TEXT("Font'/Engine/EngineFonts/TinyFont.TinyFont'"));
	
	if (Font.Succeeded()) {
		HUDFont = Font.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D>
		Texture(TEXT("Texture2D'/Game/StarterContent/Textures/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'"));
	if (Texture.Succeeded()) {
		MyTexture = Texture.Object;
	}


}

void AMyHUD::DrawHUD() {
	Super::DrawHUD();

	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX,Canvas->SizeY);
	
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	FString LifeString = FString::Printf(TEXT("Life: %d"),MyCharacter->GetLife());
	/*
	DrawTextureSimple(MyTexture, 200, 50, 1.0f, false);

	DrawTexture(MyTexture, 400, 50, MyCharacter->GetLife(),
	MyTexture->GetSizeY(), 200, 200, MyCharacter->GetLife(),
	MyTexture->GetSizeY(), FLinearColor::White,
	EBlendMode::BLEND_Opaque, 1.0f, false, 0.0f, FVector2D::ZeroVector);
	*/
	DrawText(LifeString, FColor::Black, 50, 50, HUDFont);

	

}

