#pragma once
#include <SFML/Graphics/Text.hpp>

class MenuController
{
public:
	virtual std::vector<sf::Text*>* getMenuItems() = 0;
	virtual void initializeMenu() = 0;
	virtual void selectHigherItem() = 0;
	virtual void selectLowerItem() = 0;
	virtual void selectItem() = 0;
	virtual ~MenuController() = default;
};

