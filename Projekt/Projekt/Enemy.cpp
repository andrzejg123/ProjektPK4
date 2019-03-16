#include "stdafx.h"
#include "Enemy.h"
#include "DistanceHelper.h"

void Enemy::performAction(Player* player, void* gameObjectsHolder, GameTexturesHolder* gameTexturesHolder)
{
	attackCounter++;
	const auto distance = DistanceHelper::getDistance(player->getPosition(), this->getPosition());
	const auto direction = DistanceHelper::getDirection(this->getPosition(), player->getPosition());
	if(distance < attackRadius)
	{
		if(attackCounter > attackSpeed)
		{
			attackCounter = 0;
			attack(player, gameObjectsHolder, gameTexturesHolder);
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
	} else
	{
		// todo handle time when enemy does not see enemy
	}
}
