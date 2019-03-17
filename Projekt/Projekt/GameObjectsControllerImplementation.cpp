#include "stdafx.h"
#include "GameObjectsControllerImplementation.h"

std::list<Object*>* GameObjectsControllerImplementation::getObjects() const
{
	return objects;
}

std::list<Enemy*>* GameObjectsControllerImplementation::getEnemies() const
{
	return enemies;
}

std::list<Animated*>* GameObjectsControllerImplementation::getAnimatedList() const
{
	return animatedList;
}

std::list<FlyingObject*>* GameObjectsControllerImplementation::getFlyingObjects() const
{
	return flyingObjects;
}

void GameObjectsControllerImplementation::removeFlyingObject(FlyingObject* flyingObject) const
{
	objects->remove(flyingObject);
	animatedList->remove(flyingObject);
	flyingObjects->remove(flyingObject);
	delete flyingObject;
}

Player* GameObjectsControllerImplementation::getPlayer() const
{
	return player;
}

void GameObjectsControllerImplementation::setPlayer(Player* player)
{
	this->player = player;
	objects->push_back(player);
	animatedList->push_back(player);
}

void GameObjectsControllerImplementation::addEnemy(Enemy* enemy) const
{
	enemies->push_back(enemy);
	objects->push_back(enemy);
	animatedList->push_back(enemy);
}

void GameObjectsControllerImplementation::addFlyingObject(FlyingObject* flyingObject) const
{
	objects->push_back(flyingObject);
	animatedList->push_back(flyingObject);
	flyingObjects->push_back(flyingObject);
}

GameObjectsControllerImplementation::GameObjectsControllerImplementation()
{
	objects = new std::list<Object*>();
	enemies = new std::list<Enemy*>();
	animatedList = new std::list<Animated*>();
	flyingObjects = new std::list<FlyingObject*>();
}

GameObjectsControllerImplementation::~GameObjectsControllerImplementation()
{
	for (auto object : *objects)
		delete object;
	delete animatedList;
	delete objects;
	delete enemies;
	delete flyingObjects;
}
