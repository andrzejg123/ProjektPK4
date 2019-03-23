#include "stdafx.h"
#include "ViewRouter.h"
#include "GameViewImplementation.h"
#include "OptionsViewImplementation.h"
#include "SettingsViewImplementation.h"
#include "MenuViewImplementation.h"
#include "ExtrasView.h"

void ViewRouter::openGame(sf::RenderWindow* window)
{
	GameViewImplementation(window).show();
}

void ViewRouter::openMenu(sf::RenderWindow* window)
{
	MenuViewImplementation(window).show();
}

void ViewRouter::openSettings(sf::RenderWindow* window)
{
	SettingsViewImplementation(window).show();
}

void ViewRouter::openOptions(sf::RenderWindow* window, GameViewCloseCallback* gameCloseCallback)
{
	OptionsViewImplementation(gameCloseCallback, window).show();
}

void ViewRouter::openExtras(sf::RenderWindow* window)
{
	ExtrasView(window).show();
}
