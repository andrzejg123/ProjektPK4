#pragma once
#include "OptionsView.h"
#include "OptionsController.h"
#include <SFML/Graphics.hpp>
#include "GameViewCloseCallback.h"
#include "SettingsView.h"
#include "View.h"

class OptionsViewImplementation : public OptionsView, public View
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
	void show() override;
	explicit OptionsViewImplementation(GameViewCloseCallback* gameCloseCallback, sf::RenderWindow* window);
	~OptionsViewImplementation();
};

