// Snake Game Copyright @RjTima

#pragma once

#include "CoreMinimal.h"
#include "Types.h"

namespace SnakeGame
{

	class Grid
	{
	public:
		Grid(const Dim& dim);

		Dim dim() const { return c_dim; }
	    void update(const TPositionPtr* links, CellType cellType);
	    void printDebug();

	private:
		const Dim c_dim;
		TArray<CellType> m_cells;

		void initWalls();
		FORCEINLINE uint32 posToIndex(uint32 x, uint32 y) const;
	    FORCEINLINE uint32 posToIndex(const Position& position) const;
	
	};
}