#pragma once
#include "MenuView.h"
#include "MenuController.h"
#include "GameView.h"
#include "SettingsView.h"
#include "TexturesHolder.h"

class MenuViewImplementation :
	public MenuView
{
	MenuController* menuController;
	sf::RenderWindow* window;

public:
	void showMenu() override;
	void hideMenu() override;
	void startNewGame() const override;
	void loadGame() override;
	void showExtras() override;
	void showSettings() override;
	sf::Vector2u getWindowSize() override;
	explicit MenuViewImplementation(sf::RenderWindow* window);
	~MenuViewImplementation();
};

