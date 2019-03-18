#pragma once
#include "FlyingObject.h"
#include <list>
#include "Enemy.h"

class GameObjectsHolderImplementation : public GameObjectHolder
{
	Player* player = nullptr;
	std::list<Object*>* objects;
	std::list<Enemy*>* enemies;
	std::list<Animated*>* animatedList;
	std::list<FlyingObject*>* flyingObjects;
public:
	std::list<Object*>* getObjects() const override;
	std::list<Enemy*>* getEnemies() const override;
	std::list<Animated*>* getAnimatedList() const override;
	std::list<FlyingObject*>* getFlyingObjects() const override;
	void removeFlyingObject(FlyingObject* flyingObject) const override;
	Player* getPlayer() const override;
	void setPlayer(Player* player) override;
	void addEnemy(Enemy* enemy) const override;
	void addFlyingObject(FlyingObject* flyingObject) const override;
	GameObjectsHolderImplementation();
	~GameObjectsHolderImplementation();
};

