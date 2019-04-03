#include "stdafx.h"
#include "GameObjectsHolder.h"
#include "Enemy.h"
#include "Log.h"
#include "Warrior.h"
#include <iostream>

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

std::list<Interactive*>* GameObjectsHolder::getInteractiveList() const
{
	return interactiveList;
}

void GameObjectsHolder::removeFlyingObject(FlyingObject* flyingObject) const
{
	objects->remove(flyingObject);
	animatedList->remove(flyingObject);
	flyingObjects->remove(flyingObject);
	delete flyingObject;
}

void GameObjectsHolder::removeEnemy(Enemy* enemy)
{
	objects->remove(enemy);
	animatedList->remove(enemy);
	enemies->remove(enemy);
	delete enemy;
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

void GameObjectsHolder::addInteractiveObject(Interactive* interactiveObject) const
{
	objects->push_back(interactiveObject);
	animatedList->push_back(interactiveObject);
	interactiveList->push_back(interactiveObject);
}

GameObjectsHolder::GameObjectsHolder()
{
	objects = new std::list<Object*>();
	enemies = new std::list<Enemy*>();
	animatedList = new std::list<Animated*>();
	flyingObjects = new std::list<FlyingObject*>();
	interactiveList = new std::list<Interactive*>();
}

GameObjectsHolder::~GameObjectsHolder()
{
	for (auto object : *objects)
		delete object;
	delete animatedList;
	delete objects;
	delete enemies;
	delete flyingObjects;
	delete interactiveList;
}
