#include "stdafx.h"
#include "GameObjectsController.h"

std::list<Object*>* GameObjectsController::getObjects() const
{
	return objects;
}

std::list<Enemy*>* GameObjectsController::getEnemies() const
{
	return enemies;
}

std::list<Animated*>* GameObjectsController::getAnimatedList() const
{
	return animatedList;
}

std::list<FlyingObject*>* GameObjectsController::getFlyingObjects() const
{
	return flyingObjects;
}

void GameObjectsController::removeFlyingObject(FlyingObject* flyingObject) const
{
	objects->remove(flyingObject);
	animatedList->remove(flyingObject);
	flyingObjects->remove(flyingObject);
	delete flyingObject;
}

Player* GameObjectsController::getPlayer() const
{
	return player;
}

void GameObjectsController::setPlayer(Player* player)
{
	this->player = player;
	objects->push_back(player);
	animatedList->push_back(player);
}

void GameObjectsController::addEnemy(Enemy* enemy) const
{
	enemies->push_back(enemy);
	objects->push_back(enemy);
	animatedList->push_back(enemy);
}

void GameObjectsController::addFlyingObject(FlyingObject* flyingObject) const
{
	objects->push_back(flyingObject);
	animatedList->push_back(flyingObject);
	flyingObjects->push_back(flyingObject);
}

GameObjectsController::GameObjectsController()
{
	objects = new std::list<Object*>();
	enemies = new std::list<Enemy*>();
	animatedList = new std::list<Animated*>();
	flyingObjects = new std::list<FlyingObject*>();
}

GameObjectsController::~GameObjectsController()
{
	for (auto object : *objects)
		delete object;
	delete animatedList;
	delete objects;
	delete enemies;
	delete flyingObjects;
}
