#pragma once
#include <SFML/Graphics/Text.hpp>
#include <list>

class SettingsController
{
public:
	virtual void initializeSettings() = 0;
	virtual void selectHigherItem() = 0;
	virtual void selectLowerItem() = 0;
	virtual void selectRightItem() = 0;
	virtual void selectLeftItem() = 0;
	virtual void selectItem() = 0;
	virtual std::list<sf::Text*>* getMenuItems() = 0;
	virtual ~SettingsController() = default;
};

