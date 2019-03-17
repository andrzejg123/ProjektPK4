#pragma once
#include "Animated.h"
#include <list>
#include "Player.h"
#include "FlyingObject.h"

class Enemy;

class GameObjectsController
{

public:
	virtual std::list<Object*>* getObjects() const = 0;
	virtual std::list<Enemy*>* getEnemies() const = 0;
	virtual std::list<Animated*>* getAnimatedList() const = 0;
	virtual std::list<FlyingObject*>* getFlyingObjects() const = 0;
	virtual void removeFlyingObject(FlyingObject* flyingObject) const = 0;
	virtual Player* getPlayer() const = 0;
	virtual void setPlayer(Player* player) = 0;
	virtual void addEnemy(Enemy* enemy) const = 0;
	virtual void addFlyingObject(FlyingObject* flyingObject) const = 0;
	virtual ~GameObjectsController() = default;
};
