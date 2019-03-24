#include "stdafx.h"
#include "MenuViewImplementation.h"
#include "MenuControllerImplementation.h"
#include "SettingsView.h"
#include "SettingsViewImplementation.h"
#include "GameViewImplementation.h"
#include "ViewRouter.h"

void MenuViewImplementation::show()
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
				else if (e.key.code == sf::Keyboard::Escape)
					quitGame();
			}
		}
		window.clear();
		window.draw(*menuController->getBackground());
		window.draw(*menuController->getGameName());
		for(auto menuItem: *menuController->getMenuItems())
			window.draw(*menuItem);
		window.display();
	}
}

void MenuViewImplementation::quitGame()
{
	window->close();
}

void MenuViewImplementation::startNewGame() const
{
	ViewRouter::openGame(window);
}

void MenuViewImplementation::loadGame()
{

}

void MenuViewImplementation::showExtras()
{
	ViewRouter::openExtras(window);
}

void MenuViewImplementation::showSettings()
{
	ViewRouter::openSettings(window);
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
