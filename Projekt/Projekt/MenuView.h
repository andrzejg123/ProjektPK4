#pragma once
#include <SFML/Graphics.hpp>

class MenuView
{
public:
	virtual sf::Vector2u getWindowSize() = 0;
	virtual void hideMenu() = 0;
	virtual void startNewGame() const = 0;
	virtual void showSettings() = 0;
	virtual void showExtras() = 0;
	virtual ~MenuView() = default;
	virtual void loadGame() = 0;
};

