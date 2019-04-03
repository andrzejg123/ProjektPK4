#pragma once
#include "Player.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Interactive.h"
#include <SFML/Graphics/Text.hpp>
#include "Drawer.h"

class GameViewInterfaceDrawer : public Drawer
{
	sf::RenderWindow* window;
	Player* player;
	sf::Sprite backgroundBars;
	sf::Sprite healthBar;
	sf::Sprite staminaBar;
	sf::Sprite possibleInteractionInfoBackground;
	sf::Text text;
	sf::Font font;
	Interactive* possibleInteraction;
	void drawInteractionInfo();
public:
	void draw() override;
	void setPossibleInteraction(Interactive* newPossibleInteraction);
	GameViewInterfaceDrawer(sf::RenderWindow* window, Player* player);
	~GameViewInterfaceDrawer();
};

