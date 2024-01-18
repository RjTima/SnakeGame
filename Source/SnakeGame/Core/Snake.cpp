// Copyright @2024 BY RjTima Inc., SnakeGame. All Rights Reserved.


#include "Core/Snake.h"

using namespace SnakeGame;

Snake::Snake(const Settings::Snake& settings)
{
    checkf(settings.defaultSize >= 4, TEXT("Snake length is too small: %i"), settings.defaultSize);
    //add snake list horizontally to the left [ ----* ]
    const auto startPos =  settings.startPosition;
    for(uint32 i = 0; i < settings.defaultSize; ++i)
    {
        m_links.AddTail(Position{startPos.x - i, startPos.y});
    }
}
