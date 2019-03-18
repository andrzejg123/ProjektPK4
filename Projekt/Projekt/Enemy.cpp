#include "stdafx.h"
#include "Enemy.h"
#include "DistanceHelper.h"
#include "RandomMoveControllerImplementation.h"
#include "EnemyParams.h"

void Enemy::performAction(Player* player, GameObjectHolder* gameObjectsController, GameTexturesHolder* gameTexturesHolder)
{
	attackCounter++;
	const auto distance = DistanceHelper::getDistance(player->getPosition(), this->getPosition());
	auto direction = DistanceHelper::getDirection(this->getPosition(), player->getPosition());
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
		sawPlayer = true;
	else 
		direction = randomMoveHelper->getDirection();
	move(direction);
	if (player->getFixedBounds().intersects(this->getFixedBounds()))
		cancelMove();
	setFacing(DistanceHelper::directionToFacing(this->getFacing(), direction));
	animate(AnimationType::Move);
}

Enemy::Enemy(EnemyParams* enemyParams)
{
	randomMoveHelper = new RandomMoveControllerImplementation(this);
	attackRadius = enemyParams->getAttackRadius();
	visionRadius = enemyParams->getVisionRadius();
	setPosition(sf::Vector2f(enemyParams->getPositionX(), enemyParams->getPositionY()));
	setSpeed(enemyParams->getSpeed());
	delete enemyParams;
}

Enemy::~Enemy()
{
	delete randomMoveHelper;
}
