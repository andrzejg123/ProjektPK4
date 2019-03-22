#pragma once
#include "Animated.h"
#include <list>
#include "Player.h"
#include "FlyingObject.h"
#include "Interactive.h"

class Enemy;

class GameObjectsHolder
{
	Player* player = nullptr;
	std::list<Object*>* objects;
	std::list<Enemy*>* enemies;
	std::list<Animated*>* animatedList;
	std::list<FlyingObject*>* flyingObjects;
	std::list<Interactive*>* interactiveList;
public:
	std::list<Object*>* getObjects() const;
	std::list<Enemy*>* getEnemies() const;
	std::list<Animated*>* getAnimatedList() const;
	std::list<FlyingObject*>* getFlyingObjects() const;
	void removeFlyingObject(FlyingObject* flyingObject) const;
	Player* getPlayer() const;
	void setPlayer(Player* player);
	void addEnemy(Enemy* enemy) const;
	void addFlyingObject(FlyingObject* flyingObject) const;
	void addInteractiveObject(Interactive* interactiveObject) const;
	GameObjectsHolder();
	~GameObjectsHolder();
};
