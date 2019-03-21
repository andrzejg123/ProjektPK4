#include "stdafx.h"
#include "GameMapController.h"
#include <fstream>
#include <string>

MapGameplayData* GameMapController::getGameplayData() const
{
	return gameplayData;
}

GameMapController::GameMapController(FileReadingController* fileReadingController) : fileReadingController(fileReadingController)
{
	this->map = new GameMap;
}

GameMapController::~GameMapController()
{
	delete this->map;
	delete this->collisionRects;
	delete this->drawingData;
	delete this->gameplayData;
}

bool GameMapController::checkCollision(Moveable* entity)
{
	const auto entityBounds = entity->getFixedBounds();
	if (entityBounds.left < 0.0 || entityBounds.left + entityBounds.width > 1024.0 || entityBounds.top < 0.0 || entityBounds.top + entityBounds.height > 512.0)  // NOLINT(readability-simplify-boolean-expr)
		return true;

	for (auto i = collisionRects->begin(); i != collisionRects->end(); ++i)
	{
		if (i->intersects(entityBounds))
			return true;

	}

	return false;
}

void GameMapController::loadMap(const MapIndicator mapIndicator)
{
	drawingData = fileReadingController->loadMapDrawingData(mapIndicator);
	map->load(*drawingData);
	this->collisionRects = fileReadingController->loadCollisionRects(mapIndicator);
	this->gameplayData = fileReadingController->loadMapGameplayData(mapIndicator, drawingData->tileSize);
}

GameMap* GameMapController::getMap() const
{
	return map;
}

std::list<sf::FloatRect>* GameMapController::getCollisionRects()
{
	return collisionRects;
}
