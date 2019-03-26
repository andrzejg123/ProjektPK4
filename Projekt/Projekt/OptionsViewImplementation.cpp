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

void OptionsViewImplementation::handleEvent(sf::RenderWindow& window)
{
	sf::Event e;
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::MouseMoved)
			optionsController->mouseMove(e.mouseMove.x, e.mouseMove.y);
		else if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::W)
				optionsController->selectHigherItem();
			else if (e.key.code == sf::Keyboard::S)
				optionsController->selectLowerItem();
			else if (e.key.code == sf::Keyboard::Enter)
				optionsController->selectItem();
			else if (e.key.code == sf::Keyboard::Escape)
				resumeGame();
		}
		else if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
			optionsController->mouseClick(e.mouseButton.x, e.mouseButton.y);
		else if (e.type == sf::Event::Closed)
			window.close();
	}
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
		handleEvent(window);
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
	overlay->setSize(sf::Vector2f(static_cast<float>(windowSize.x), static_cast<float>(windowSize.y)));
	overlay->setFillColor(sf::Color(255, 255, 255, 64));
	this->optionsController = new OptionsControllerImplementation(this);
}

OptionsViewImplementation::~OptionsViewImplementation()
{
	delete optionsController;
	delete overlay;
}
