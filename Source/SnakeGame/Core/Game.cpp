// Snake Game Copyright @RjTima


#include "Game.h"
#include "SnakeGame/Core/Game.h"
#include "SnakeGame/Core/Grid.h"
#include "SnakeGame/Core/Snake.h"

DEFINE_LOG_CATEGORY_STATIC(LogGame, All, All);

using namespace SnakeGame;

Game::Game(const Settings& settings): c_settings(settings)
{
	m_grid = MakeShared<Grid>(settings.gridDims);
    m_snake = MakeShared<Snake>(settings.snake);

    m_grid->update(m_snake->body(), CellType::Snake);
    m_grid->printDebug();
}
