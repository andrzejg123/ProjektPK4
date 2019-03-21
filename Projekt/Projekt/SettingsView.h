#pragma once
#include <SFML/System/Vector2.hpp>

class SettingsView
{
public:
	virtual sf::Vector2u getWindowSize() = 0;
	virtual void showSettings() = 0;
	virtual void hideSettings() = 0;
	virtual ~SettingsView() = default;
};

