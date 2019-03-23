#pragma once
#include "OptionsView.h"
#include "OptionsController.h"
#include <SFML/Graphics.hpp>
#include "GameViewCloseCallback.h"
#include "SettingsView.h"

class OptionsViewImplementation : public OptionsView
{
	GameViewCloseCallback* gameCloseCallback;
	OptionsController* optionsController;
	sf::RectangleShape* overlay;
	sf::RenderWindow* window;
	bool shouldShowOptions = true;

public:
	void quitGame() override;
	void openSettings() override;
	void openMainMenu() override;
	sf::Vector2u getWindowSize() override;
	void resumeGame() override;
	void openOptions() override;
	explicit OptionsViewImplementation(GameViewCloseCallback* gameCloseCallback, sf::RenderWindow* window);
	~OptionsViewImplementation();
};

