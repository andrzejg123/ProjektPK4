#include "stdafx.h"
#include "GameControllerImplementation.h"
#include <iostream>

void GameControllerImplementation::getFirstLayer()
{
	return;
}

GameControllerImplementation::GameControllerImplementation(GameView* gameView): gameView(gameView)
{
	std::cout << "halo";
}

GameControllerImplementation::~GameControllerImplementation()
{
}
