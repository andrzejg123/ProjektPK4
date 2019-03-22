#include "stdafx.h"
#include "GameObjectsHolderImplementation.h"

std::list<Object*>* GameObjectsHolderImplementation::getObjects() const
{
	return objects;
}

std::list<Enemy*>* GameObjectsHolderImplementation::getEnemies() const
{
	return enemies;
}

std::list<Animated*>* GameObjectsHolderImplementation::getAnimatedList() const
{
	return animatedList;
}

std::list<FlyingObject*>* GameObjectsHolderImplementation::getFlyingObjects() const
{
	return flyingObjects;
}

void GameObjectsHolderImplementation::removeFlyingObject(FlyingObject* flyingObject) const
{
	objects->remove(flyingObject);
	animatedList->remove(flyingObject);
	flyingObjects->remove(flyingObject);
	delete flyingObject;
}

Player* GameObjectsHolderImplementation::getPlayer() const
{
	return player;
}

void GameObjectsHolderImplementation::setPlayer(Player* player)
{
	this->player = player;
	objects->push_back(player);
	animatedList->push_back(player);
}

void GameObjectsHolderImplementation::addEnemy(Enemy* enemy) const
{
	enemies->push_back(enemy);
	objects->push_back(enemy);
	animatedList->push_back(enemy);
}

void GameObjectsHolderImplementation::addFlyingObject(FlyingObject* flyingObject) const
{
	objects->push_back(flyingObject);
	animatedList->push_back(flyingObject);
	flyingObjects->push_back(flyingObject);
}

void GameObjectsHolderImplementation::addInteractiveObject(Interactive* interactiveObject)
{
	objects->push_back(interactiveObject);
	animatedList->push_back(interactiveObject);
	interactiveList->push_back(interactiveObject);
}

GameObjectsHolderImplementation::GameObjectsHolderImplementation()
{
	objects = new std::list<Object*>();
	enemies = new std::list<Enemy*>();
	animatedList = new std::list<Animated*>();
	flyingObjects = new std::list<FlyingObject*>();
	interactiveList = new std::list<Interactive*>();
}

GameObjectsHolderImplementation::~GameObjectsHolderImplementation()
{
	for (auto object : *objects)
		delete object;
	delete animatedList;
	delete objects;
	delete enemies;
	delete flyingObjects;
	delete interactiveList;
}
