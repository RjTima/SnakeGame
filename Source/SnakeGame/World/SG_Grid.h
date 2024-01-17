// Snake Game Copyright @RjTima

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Types.h"
#include "World/SG_WorldTypes.h"
#include "SG_Grid.generated.h"

namespace Snake
{ 
	class Grid;
}

class UStaticMeshComponent;

UCLASS()
class SNAKEGAME_API ASG_Grid : public AActor
{
	GENERATED_BODY()
	
public:	
	ASG_Grid();
	virtual void Tick(float DeltaTime) override;
	void SetModel(const TSharedPtr<Snake::Grid>& Grid, uint32 CellSize);

    void UpdateColors(const FSnakeColors& Colors);

protected:

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<USceneComponent> Origin;

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<UStaticMeshComponent> GridMesh;
    
	virtual void BeginPlay() override;

private:
    UPROPERTY()
        UMaterialInstanceDynamic* GridMaterial;
	Snake::Dim GridDim;
	uint32 CellSize;
	uint32 WorldWidth;
	uint32 WorldHeight;

	void DrawGrid();

};
