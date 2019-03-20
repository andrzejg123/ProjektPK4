#pragma once
#include "GameMap.h"
#include <list>
#include "FileReadingController.h"
#include "Moveable.h"
#include "SpawnArea.h"

class GameMapController
{
	GameMap* map;
	std::list<sf::FloatRect>* collisionRects = nullptr;
	FileReadingController *fileReadingController;
	MapDrawingData* drawingData = nullptr;
	MapGameplayData* gameplayData = nullptr;
public:
	GameMapController(FileReadingController* fileReadingController);
	~GameMapController();
	bool checkCollision(Moveable* entity);
	void loadMap(MapIndicator mapIndicator);
	GameMap* getMap() const;
	MapGameplayData* getGameplayData() const;
	std::list<sf::FloatRect>* getCollisionRects();
};

