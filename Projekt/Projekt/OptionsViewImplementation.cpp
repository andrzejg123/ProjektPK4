#include "stdafx.h"
#include "OptionsViewImplementation.h"
#include "OptionsControllerImplementation.h"
#include "SettingsViewImplementation.h"
#include "ViewRouter.h"

void OptionsViewImplementation::quitGame()
{
	window->close();
}

void OptionsViewImplementation::openSettings()
{
	ViewRouter::openSettings(window);
}

void OptionsViewImplementation::openMainMenu()
{
	gameCloseCallback->closeGame();
	resumeGame();
}

sf::Vector2u OptionsViewImplementation::getWindowSize()
{
	return window->getSize();
}

void OptionsViewImplementation::resumeGame()
{
	shouldShowOptions = false;
}

void OptionsViewImplementation::show()
{
	auto& window = *this->window;
	sf::Texture a;
	a.create(window.getSize().x, window.getSize().y);
	a.update(window);
	const auto background = sf::Sprite(a);
	optionsController->initializeOptions();
	while (window.isOpen() && shouldShowOptions)
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::W)
					optionsController->selectLowerItem();
				else if (e.key.code == sf::Keyboard::S)
					optionsController->selectHigherItem();
				else if (e.key.code == sf::Keyboard::Enter)
					optionsController->selectItem();
				else if (e.key.code == sf::Keyboard::Escape)
					resumeGame();
			}
		}
		window.clear();
		window.draw(background);
		window.draw(*overlay);
		window.draw(*optionsController->getBackgroundBorders());
		window.draw(*optionsController->getItemsBackground());
		for (auto optionsItem : *optionsController->getOptionsItems())
			window.draw(*optionsItem);
		window.display();
	}
}

OptionsViewImplementation::OptionsViewImplementation(GameViewCloseCallback* gameCloseCallback, sf::RenderWindow* window)
{
	this->window = window;
	this->gameCloseCallback = gameCloseCallback;
	const auto windowSize = window->getSize();
	overlay = new sf::RectangleShape(sf::Vector2f(0, 0));
	overlay->setSize(sf::Vector2f(windowSize.x, windowSize.y));
	overlay->setFillColor(sf::Color(255, 255, 255, 64));
	this->optionsController = new OptionsControllerImplementation(this);
}

OptionsViewImplementation::~OptionsViewImplementation()
{
	delete optionsController;
	delete overlay;
}
