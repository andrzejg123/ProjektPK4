#pragma once
#include "GameController.h"
#include "GameView.h"
#include "DebugDrawer.h"

class GameViewImplementation: GameView
{
	GameController* gameController;
	DebugDrawer* debugDrawer;
	sf::RenderWindow* window;

public:
	void displayGame() const;
	GameViewImplementation(sf::RenderWindow* window);
	~GameViewImplementation();
};

