// Copyright @2024 BY RjTima Inc., SnakeGame. All Rights Reserved.


#include "Framework/SG_GameMode.h"
#include "SG_GameMode.h"
#include "SG_Pawn.h"
#include "Core/Grid.h"
#include "SnakeGame/Core/Types.h"
#include "World/SG_Grid.h"
#include "World/SG_WorldTypes.h"
#include "Engine/ExponentialHeightFog.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Kismet/GameplayStatics.h"

void ASG_GameMode::StartPlay()
{
	Super::StartPlay();
    
    //init core game
	SnakeGame::Settings GS;
    GS.gridDims = SnakeGame::Dim{GridSize.X, GridSize.Y};
    GS.snake.defaultSize = SnakeDefaultSize;
    GS.snake.startPosition = SnakeGame::Position{GridSize.X / 2, GridSize.Y / 2};
	Game = MakeUnique < SnakeGame::Game>(GS);
	check(Game.IsValid());

    //init world grid
	const FTransform GridOrigin = FTransform::Identity;
	check(GetWorld());
	GridVisual = GetWorld()->SpawnActorDeferred<ASG_Grid>(GridVisualClass, GridOrigin);
	check(GridVisual);
	GridVisual->SetModel(Game->grid(), CellSize);
	GridVisual->FinishSpawning(GridOrigin);

    //set pawn location fitting grid in viewport
    auto* PC = GetWorld()->GetFirstPlayerController();
    check(PC);
    auto* Pawn = Cast<ASG_Pawn>(PC->GetPawn());
    check(Pawn);
    check(Game->grid().IsValid());
    Pawn->UpdateLocation(Game->grid()->dim(),CellSize,GridOrigin);

    //
    FindFog();
    
    //Update colors
    check(ColorsTable);
    const auto RowsCount = ColorsTable->GetRowNames().Num();
    check(RowsCount >= 1);
    ColorTableIndex = FMath::RandRange(0,RowsCount - 1);
    UpdateColors();
    
}

void ASG_GameMode::NextColor()
{
    if(ColorsTable)
    {
        ColorTableIndex = (ColorTableIndex + 1) % ColorsTable->GetRowNames().Num();
        UpdateColors();
    }
    
}

void ASG_GameMode::FindFog()
{
    TArray<AActor*> Fogs;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AExponentialHeightFog::StaticClass(),Fogs);
    if(Fogs.Num() > 0)
    {
        Fog = Cast<AExponentialHeightFog>(Fogs[0]);
    }
    
}

void ASG_GameMode::UpdateColors()
{
    const auto RowName = ColorsTable->GetRowNames()[ColorTableIndex];
    const auto* ColorSet = ColorsTable->FindRow<FSnakeColors>(RowName, {});
    if(ColorSet)
    {
        //update grid
        GridVisual->UpdateColors(*ColorSet);

        //update scene ambient color via fog
        if(Fog && Fog->GetComponent())
        {
            Fog->GetComponent()->SkyAtmosphereAmbientContributionColorScale = ColorSet->SkyAtmosphereColor;
            Fog->MarkComponentsRenderStateDirty();
        }
    }
}
