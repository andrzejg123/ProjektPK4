#pragma once
#include <SFML/System/Vector2.hpp>

class OptionsView
{
public:
	virtual void quitGame() = 0;
	virtual void openMainMenu() = 0;
	virtual void openSettings() = 0;
	virtual void resumeGame() = 0;
	virtual sf::Vector2u getWindowSize() = 0;
	virtual ~OptionsView() = default;
};

