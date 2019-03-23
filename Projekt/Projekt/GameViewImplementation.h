#pragma once
#include "GameController.h"
#include "GameView.h"
#include "DebugDrawer.h"
#include "OptionsView.h"
#include "GameViewCloseCallback.h"

class GameViewImplementation: public GameView, public GameViewCloseCallback
{
	GameController* gameController;
	DebugDrawer* debugDrawer;
	sf::RenderWindow* window;
	bool shouldShowGame = true;

public:
	void closeGame() override;
	void displayGame() override;
	sf::Vector2u getWindowSize() override;
	explicit GameViewImplementation(sf::RenderWindow* window);
	~GameViewImplementation();
};

