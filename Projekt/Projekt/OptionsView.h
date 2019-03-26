#pragma once
#include <SFML/System/Vector2.hpp>

class OptionsView
{
public:
	//Closes all windows
	virtual void quitGame() = 0;
	//Closes option window and game window
	virtual void openMainMenu() = 0;
	//Opens settings window
	virtual void openSettings() = 0;
	//Closes option window
	virtual void resumeGame() = 0;
	//Return window size
	virtual sf::Vector2u getWindowSize() = 0;
	virtual ~OptionsView() = default;
};

