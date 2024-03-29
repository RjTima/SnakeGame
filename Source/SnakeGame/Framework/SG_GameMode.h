// Snake Game Copyright @RjTima// Copyright @2024 BY RjTima Inc., SnakeGame. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGame/Core/Game.h"
#include "Engine/DataTable.h"
#include "SG_GameMode.generated.h"

/**
 * 
 */
class ASG_Grid;
class AExponentialHeightFog;

UCLASS()
class SNAKEGAME_API ASG_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "10", ClampMax = "100"))
	FUintPoint GridSize {10, 10};

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "10", ClampMax = "100"))
	uint32 CellSize {10};

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "4", ClampMax = "10"))
    uint32 SnakeDefaultSize {5};

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASG_Grid> GridVisualClass;

    UPROPERTY(EditDefaultsOnly, Category = "Design")
        UDataTable* ColorsTable;
private:
	UPROPERTY()
	ASG_Grid* GridVisual;

    UPROPERTY()
    AExponentialHeightFog* Fog;

    UFUNCTION(Exec, Category = "Console command")
    void NextColor();
    
    TUniquePtr<SnakeGame::Game> Game;
    uint32 ColorTableIndex{0};

    void FindFog();
    void UpdateColors();

};
