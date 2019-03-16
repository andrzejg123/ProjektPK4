#include "stdafx.h"
#include "GameObjectsHolder.h"

std::list<Object*>* GameObjectsHolder::getObjects() const
{
	return objects;
}

std::list<Enemy*>* GameObjectsHolder::getEnemies() const
{
	return enemies;
}

std::list<Animated*>* GameObjectsHolder::getAnimatedList() const
{
	return animatedList;
}

std::list<FlyingObject*>* GameObjectsHolder::getFlyingObjects() const
{
	return flyingObjects;
}

void GameObjectsHolder::removeFlyingObject(FlyingObject* flyingObject) const
{
	objects->remove(flyingObject);
	animatedList->remove(flyingObject);
	flyingObjects->remove(flyingObject);
	delete flyingObject;
}

Player* GameObjectsHolder::getPlayer() const
{
	return player;
}

void GameObjectsHolder::setPlayer(Player* player)
{
	this->player = player;
	objects->push_back(player);
	animatedList->push_back(player);
}

void GameObjectsHolder::addEnemy(Enemy* enemy) const
{
	enemies->push_back(enemy);
	objects->push_back(enemy);
	animatedList->push_back(enemy);
}

void GameObjectsHolder::addFlyingObject(FlyingObject* flyingObject) const
{
	objects->push_back(flyingObject);
	animatedList->push_back(flyingObject);
	flyingObjects->push_back(flyingObject);
}

GameObjectsHolder::GameObjectsHolder()
{
	objects = new std::list<Object*>();
	enemies = new std::list<Enemy*>();
	animatedList = new std::list<Animated*>();
	flyingObjects = new std::list<FlyingObject*>();
}

GameObjectsHolder::~GameObjectsHolder()
{
	for (auto object : *objects)
		delete object;
	delete animatedList;
	delete objects;
	delete enemies;
	delete flyingObjects;
}
