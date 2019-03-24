#pragma once
#include <SFML/Graphics.hpp>

class MenuController
{
public:
	virtual void mouseMove(float x, float y) = 0;
	virtual void mouseClick(float x, float y) = 0;
	virtual sf::Sprite* getBackground() = 0;
	virtual std::vector<sf::Text*>* getMenuItems() = 0;
	virtual sf::Text* getGameName() = 0;
	virtual void initializeMenu() = 0;
	virtual void selectHigherItem() = 0;
	virtual void selectLowerItem() = 0;
	virtual void selectItem() = 0;
	virtual ~MenuController() = default;
};

