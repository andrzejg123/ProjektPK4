#pragma once
#include "GameMap.h"
#include <list>
#include "FileReadingController.h"
#include "Moveable.h"

class GameMapController
{
	GameMap* map;
	std::list<sf::FloatRect>* collisionRects = nullptr;
	FileReadingController* fileReadingController;
	
public:
	GameMapController();
	~GameMapController();
	bool checkCollision(Moveable* entity);
	void loadMap(MapDataIndicator dataIndicator);
	GameMap* getMap() const;
	std::list<sf::FloatRect>* getCollisionRects();
};

