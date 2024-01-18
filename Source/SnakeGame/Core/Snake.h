// Copyright @2024 BY RjTima Inc., SnakeGame. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types.h"

namespace SnakeGame
{
class SNAKEGAME_API Snake
{
public:
    Snake(const Settings::Snake& settings);

    const TSnakeList& links() const {return m_links;}
    const Position head() const {return m_links.GetHead()->GetValue();}
    const TPositionPtr* body() const {return m_links.GetHead()->GetNextNode();}
    
private:
    TSnakeList m_links;
};
}