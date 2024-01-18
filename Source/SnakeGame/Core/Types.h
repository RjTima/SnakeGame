// Snake Game Copyright @RjTima

#pragma once

#include "CoreMinimal.h"

namespace SnakeGame
{

	struct Dim
	{
		uint32 width;
		uint32 height;
	};

	enum class CellType
	{
		Empty = 0,
		Wall
		//Food
		//Snake
	};

	struct Settings
	{
		Dim gridDims;
	};
}