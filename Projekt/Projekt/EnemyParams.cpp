#include "stdafx.h"
#include "EnemyParams.h"

float EnemyParams::getAttackRadius() const
{
	return attackRadius;
}

float EnemyParams::getVisionRadius() const
{
	return visionRadius;
}

float EnemyParams::getPositionX() const
{
	return positionX;
}

float EnemyParams::getPositionY() const
{
	return positionY;
}

float EnemyParams::getSpeed() const
{
	return speed;
}

EnemyParams::Builder& EnemyParams::Builder::setSpeed(const float speed)
{
	enemyParams->speed = speed;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setPosition(const float positionX, const float positionY)
{
	enemyParams->positionX = positionX;
	enemyParams->positionY = positionY;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setVisionRadius(const float visionRadius)
{
	enemyParams->visionRadius = visionRadius;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setAttackRadius(const float attackRadius)
{
	enemyParams->attackRadius = attackRadius;
	return *this;
}

EnemyParams* EnemyParams::Builder::build() const
{
	return enemyParams;
}

EnemyParams::Builder::Builder()
{
	this->enemyParams = new EnemyParams();
}
