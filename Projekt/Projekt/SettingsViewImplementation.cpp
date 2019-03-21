#include "stdafx.h"
#include "SettingsViewImplementation.h"
#include "SettingsControllerImplementation.h"
#include <SFML/Graphics.hpp>

sf::Vector2u SettingsViewImplementation::getWindowSize()
{
	return window->getSize();
}

void SettingsViewImplementation::showSettings()
{
	auto& window = *this->window;
	settingsController->initializeSettings();
	while (window.isOpen() && shouldShowSettings)
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::W)
					settingsController->selectHigherItem();
				else if (e.key.code == sf::Keyboard::S)
					settingsController->selectLowerItem();
				else if (e.key.code == sf::Keyboard::A)
					settingsController->selectLeftItem();
				else if (e.key.code == sf::Keyboard::D)
					settingsController->selectRightItem();
				else if (e.key.code == sf::Keyboard::Enter)
					settingsController->selectItem();
			}
		}
		window.clear();
		for (auto menuItem : *settingsController->getMenuItems())
			window.draw(*menuItem);
		window.display();
	}
}

void SettingsViewImplementation::hideSettings()
{
	shouldShowSettings = false;
}

SettingsViewImplementation::SettingsViewImplementation(sf::RenderWindow* window)
{
	this->window = window;
	this->settingsController = new SettingsControllerImplementation(this);
}

SettingsViewImplementation::~SettingsViewImplementation()
{
	delete settingsController;
}
