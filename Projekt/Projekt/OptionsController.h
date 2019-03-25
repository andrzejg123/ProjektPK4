#pragma once
#include <SFML/Graphics.hpp>

class OptionsController
{
public:
	virtual void mouseMove(float x, float y) = 0;
	virtual void mouseClick(float x, float y) = 0;
	virtual sf::Sprite* getItemsBackground() = 0;
	virtual sf::RectangleShape* getBackgroundBorders() = 0;
	virtual std::vector<sf::Text*>* getOptionsItems() = 0;
	virtual void initializeOptions() = 0;
	virtual void selectHigherItem() = 0;
	virtual void selectLowerItem() = 0;
	virtual void selectItem() = 0;
	virtual ~OptionsController() = default;
};

