#pragma once
#include <SFML/System/Vector2.hpp>

class GameView
{
public:
	virtual sf::Vector2u getWindowSize() = 0;
	virtual ~GameView() = default;
};

