#include "stdafx.h"
#include "SettingsViewImplementation.h"
#include "SettingsControllerImplementation.h"
#include <SFML/Graphics.hpp>

void SettingsViewImplementation::handleEvent(sf::RenderWindow& window)
{
	sf::Event e;
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::MouseMoved)
			settingsController->mouseMove(e.mouseMove.x, e.mouseMove.y);
		else if (e.type == sf::Event::KeyPressed)
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
			else if (e.key.code == sf::Keyboard::Escape)
				hideSettings();
		}
		else if (e.type == sf::Event::MouseButtonPressed)
		{
			if (e.mouseButton.button == sf::Mouse::Left)
				settingsController->mouseLeftClick(e.mouseButton.x, e.mouseButton.y);
			else if (e.mouseButton.button == sf::Mouse::Right)
				settingsController->mouseRightClick(e.mouseButton.x, e.mouseButton.y);
		}
		else if (e.type == sf::Event::Closed)
			window.close();
	}
}

void SettingsViewImplementation::updateWindowParams(const SettingsData settingsData)
{
	window->setFramerateLimit(settingsData.frameRateLimit);
	window->setVerticalSyncEnabled(settingsData.vSyncEnabled);
}

sf::Vector2u SettingsViewImplementation::getWindowSize()
{
	return window->getSize();
}

void SettingsViewImplementation::show()
{
	auto& window = *this->window;
	settingsController->initializeSettings();
	while (window.isOpen() && shouldShowWindow)
	{
		handleEvent(window);
		window.clear();
		window.draw(*settingsController->getBackground());
		for (auto menuItem : *settingsController->getMenuItems())
			window.draw(*menuItem);
		window.display();
	}
}

void SettingsViewImplementation::hideSettings()
{
	shouldShowWindow = false;
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
