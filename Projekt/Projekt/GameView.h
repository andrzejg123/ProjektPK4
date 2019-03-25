#pragma once
#include <SFML/System/Vector2.hpp>
#include "Interactive.h"

class GameView
{
public:
	virtual sf::Vector2u getWindowSize() = 0;
	virtual void setPossibleInteraction(Interactive* newPossibleInteraction) = 0;
	virtual ~GameView() = default;
};

