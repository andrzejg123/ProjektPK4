#pragma once
#include <SFML/Graphics.hpp>
#include "GameViewCloseCallback.h"

class ViewRouter
{
public:
	static void openGame(sf::RenderWindow* window);
	static void openMenu(sf::RenderWindow* window);
	static void openSettings(sf::RenderWindow* window);
	static void openOptions(sf::RenderWindow* window, GameViewCloseCallback* gameCloseCallback);
	static void openExtras(sf::RenderWindow* window);
};

