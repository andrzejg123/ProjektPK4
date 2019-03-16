#include "stdafx.h"
#include "GameMapController.h"
#include <fstream>
#include <string>

GameMapController::GameMapController()
{
	this->map = new GameMap;
	this->fileReadingController = new FileReadingController;
}

GameMapController::~GameMapController()
{
	delete this->map;
	delete this->fileReadingController;
	delete this->collisionRects;
}

bool GameMapController::checkCollision(Moveable* entity)
{
	const auto entityBounds = entity->getFixedBounds();

	for (auto i = collisionRects->begin(); i != collisionRects->end(); ++i)
	{
		if (i->intersects(entityBounds))
			return true;

	}

	return false;
}

void GameMapController::loadMap(const MapDataIndicator dataIndicator)
{
	const auto mapData = fileReadingController->loadMapData(dataIndicator);
	map->load(*mapData);
	delete mapData;
	this->collisionRects = fileReadingController->loadCollisionRects(dataIndicator);
}

GameMap* GameMapController::getMap() const
{
	return map;
}
