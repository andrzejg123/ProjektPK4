#pragma once
#include <SFML/System/Vector2.hpp>

class GameView
{
public:
	virtual void displayGame() = 0;
	virtual sf::Vector2u getWindowSize() = 0;
	virtual ~GameView() = default;
};

