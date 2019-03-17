#include "stdafx.h"
#include "Enemy.h"
#include "DistanceHelper.h"
#include "RandomMoveControllerImplementation.h"

void Enemy::performAction(Player* player, GameObjectsController* gameObjectsController, GameTexturesHolder* gameTexturesHolder)
{
	attackCounter++;
	const auto distance = DistanceHelper::getDistance(player->getPosition(), this->getPosition());
	const auto direction = DistanceHelper::getDirection(this->getPosition(), player->getPosition());
	if(distance < attackRadius)
	{
		if(attackCounter > attackSpeed)
		{
			attackCounter = 0;
			attack(player, gameObjectsController, gameTexturesHolder);
			setFacing(DistanceHelper::directionToFacing(this->getFacing(), direction));
		}
		stopAnimate(AnimationType::Move);
		return;
	}
	if(sawPlayer || distance < visionRadius)
	{
		sawPlayer = true;
		move(direction);
		if (player->getFixedBounds().intersects(this->getFixedBounds()))
			cancelMove();
		setFacing(DistanceHelper::directionToFacing(this->getFacing(), direction));
		animate(AnimationType::Move);
		return;
	}
	const auto randomDirection = randomMoveHelper->getDirection();
	move(randomDirection);
	if (player->getFixedBounds().intersects(this->getFixedBounds()))
		cancelMove();
	setFacing(DistanceHelper::directionToFacing(this->getFacing(), randomDirection));
	animate(AnimationType::Move);
}

Enemy::Enemy()
{
	randomMoveHelper = new RandomMoveControllerImplementation(this);
}

Enemy::~Enemy()
{
	delete randomMoveHelper;
}
