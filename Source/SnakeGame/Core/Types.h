// Snake Game Copyright @RjTima

#pragma once

#include "CoreMinimal.h"
#include "Containers/List.h"

namespace SnakeGame
{

	struct Dim
	{
		uint32 width;
		uint32 height;
	};

    struct Position
    {
        Position(uint32 inX, uint32 inY): x(inX), y(inY) {}
        uint32 x;
        uint32 y;
    };

	enum class CellType
	{
		Empty = 0,
		Wall,
	    Snake
		//Food
	};

	struct Settings
	{
		Dim gridDims{40,10};

        struct Snake
        {
            uint32 defaultSize{4};
            Position startPosition{0,0};
        }snake;
	};

using TSnakeList = TDoubleLinkedList<Position>;
using TPositionPtr = TSnakeList::TDoubleLinkedListNode;
}
