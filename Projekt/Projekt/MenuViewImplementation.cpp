#include "stdafx.h"
#include "MenuViewImplementation.h"
#include "MenuControllerImplementation.h"
#include <windows.h>
#include "SettingsView.h"
#include "SettingsViewImplementation.h"
#include "GameViewImplementation.h"

void MenuViewImplementation::showMenu()
{
	auto& window = *this->window;
	menuController->initializeMenu();
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::W)
					menuController->selectHigherItem();
				else if (e.key.code == sf::Keyboard::S)
					menuController->selectLowerItem();
				else if (e.key.code == sf::Keyboard::Enter)
					menuController->selectItem();
			}
		}
		window.clear();
		for(auto menuItem: *menuController->getMenuItems())
			window.draw(*menuItem);
		window.display();
	}
}

void MenuViewImplementation::hideMenu()
{
	window->close();
}

void MenuViewImplementation::startNewGame() const
{
	const auto gameView = new GameViewImplementation(window);
	gameView->displayGame();
	delete gameView;
}

void MenuViewImplementation::loadGame()
{

}

void MenuViewImplementation::showExtras()
{

}

void MenuViewImplementation::showSettings()
{
	SettingsView* settingsView = new SettingsViewImplementation(window);
	settingsView->showSettings();
	delete settingsView;
}

sf::Vector2u MenuViewImplementation::getWindowSize()
{
	return window->getSize();
}

MenuViewImplementation::MenuViewImplementation(sf::RenderWindow* window)
{
	this->window = window;
	menuController = new MenuControllerImplementation(this);
}

MenuViewImplementation::~MenuViewImplementation()
{
	delete menuController;
}
