#pragma once
#include "Player.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Interactive.h"
#include <SFML/Graphics/Text.hpp>

class GameViewInterfaceDrawer
{
	sf::RenderWindow* window;
	sf::Sprite backgroundBars;
	sf::Sprite healthBar;
	sf::Sprite staminaBar;
	sf::Sprite possibleInteractionInfoBackground;
	sf::Text text;
	sf::Font font;
	Interactive* possibleInteraction;
	void drawInteractionInfo();
public:
	void draw(Player* player);
	void setPossibleInteraction(Interactive* newPossibleInteraction);
	GameViewInterfaceDrawer(sf::RenderWindow* window);
	~GameViewInterfaceDrawer();
};

