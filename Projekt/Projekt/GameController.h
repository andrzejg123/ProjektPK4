#pragma once
#include "GameMap.h"
#include <list>
#include "GameObjectsHolder.h"
#include <SFML/Graphics.hpp>

class GameController
{
public:
	virtual ~GameController() = default;
	virtual void getFirstLayer() = 0;
	virtual void initializeGame() = 0;
	virtual GameMap* getMap() = 0;
	virtual void movePlayer(Direction direction, sf::Time& elapsedTime) = 0;
	virtual void stopPlayer() = 0;
	virtual void updateGame(sf::Time& elapsed) = 0;
	virtual std::list<Object*>* getObjectsToDraw() = 0;
	virtual GameObjectsHolder* getGameObjectHolder() = 0;
	virtual std::list<sf::FloatRect>* getCollisionRects() = 0;
	virtual void playerInteract() = 0;
};


