#include "stdafx.h"
#include "GameControllerImplementation.h"

void GameControllerImplementation::getFirstLayer()
{
	return;
}

void GameControllerImplementation::initializeGame()
{
	gameMapController->loadMap(MapDataIndicator::Test);
	auto& playerTexture = gameTexturesHolder->getTexture(TextureIndicator::PlayerWarrior);
	this->player = new Player(playerTexture);
}

Player* GameControllerImplementation::getPlayer()
{
	return player;
}

void GameControllerImplementation::movePlayer(const Direction direction)
{
	player->move(direction);
	if (gameMapController->checkCollision(player))
		player->cancelMove();

	auto playerFacing = player->getFacing();
	switch(direction)
	{
	case Direction::UpLeft:
		if (playerFacing != Facing::Left)
			playerFacing = Facing::Up;
		break;
	case Direction::DownLeft:
		if (playerFacing != Facing::Left)
			playerFacing = Facing::Down;
		break;
	case Direction::DownRight:
		if (playerFacing != Facing::Right)
			playerFacing = Facing::Down;
		break;
	case Direction::UpRight:
		if (playerFacing != Facing::Right)
			playerFacing = Facing::Up;
		break;
	default: playerFacing = Facing(direction);
	}
	player->setFacing(playerFacing);
	player->animate(AnimationType::Move);
}

void GameControllerImplementation::stopPlayer()
{
	player->stopAnimate();
}

void GameControllerImplementation::updateGame(const sf::Time& elapsed)
{
	player->updateAnimation(elapsed);
}

GameMap* GameControllerImplementation::getMap()
{
	return gameMapController->getMap();
}

GameControllerImplementation::GameControllerImplementation(GameView* gameView): gameView(gameView)
{
	this->gameMapController = new GameMapController;
	this->gameTexturesHolder = new GameTexturesHolder;
}

GameControllerImplementation::~GameControllerImplementation()
{
	delete this->gameMapController;
	delete this->gameTexturesHolder;
	delete this->player;
}
