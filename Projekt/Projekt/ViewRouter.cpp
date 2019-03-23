#include "stdafx.h"
#include "ViewRouter.h"
#include "GameViewImplementation.h"
#include "OptionsViewImplementation.h"
#include "SettingsViewImplementation.h"
#include "MenuViewImplementation.h"

void ViewRouter::openGame(sf::RenderWindow* window)
{
	GameViewImplementation(window).displayGame();
}

void ViewRouter::openMenu(sf::RenderWindow* window)
{
	MenuViewImplementation(window).showMenu();
}

void ViewRouter::openSettings(sf::RenderWindow* window)
{
	SettingsViewImplementation(window).showSettings();
}

void ViewRouter::openOptions(sf::RenderWindow* window, GameViewCloseCallback* gameCloseCallback)
{
	OptionsViewImplementation(gameCloseCallback, window).openOptions();
}
