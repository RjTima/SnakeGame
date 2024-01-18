// Snake Game Copyright @RjTima

#pragma once

#include "CoreMinimal.h"
#include "Types.h"

namespace SnakeGame
{
	class Grid;
    class Snake;

	class Game
	{
	public:
		Game(const Settings& settings);
		TSharedPtr<Grid> grid() const { return m_grid; }
	    TSharedPtr<Snake> snake() const { return m_snake; }

	private:
		const Settings c_settings;
		TSharedPtr<Grid> m_grid;
	    TSharedPtr<Snake> m_snake;
	};
}
