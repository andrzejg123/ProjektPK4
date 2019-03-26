#include "stdafx.h"
#include "EnemyParams.h"
#include "Log.h"

EnemyParams::EnemyParams(const int lvl) : level(lvl)
{
	const auto floatLvl = float(lvl);
	attackRadius = 0.0f;
	positionX = 0.0f;
	positionY = 0.0f;
	speed = 60.0f + floatLvl;
	visionRadius = 110.0f + lvl;
	health = 100.0f + (floatLvl * 2.0f);
	armor = 100.0f + (floatLvl * 2.0f);
	damage = 20.0f + floatLvl;
}

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

float EnemyParams::getHealth() const
{
	return health;
}

float EnemyParams::getArmor() const
{
	return armor;
}

float EnemyParams::getDamage() const
{
	return damage;
}

int EnemyParams::getLevel() const
{
	return level;
}

EnemyParams::Builder& EnemyParams::Builder::multiplySpeedByValue(const float value)
{
	enemyParams->speed *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyHealthByValue(const float value)
{
	enemyParams->health *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyArmorByValue(const float value)
{
	enemyParams->armor *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setPosition(const float positionX, const float positionY)
{
	enemyParams->positionX = positionX;
	enemyParams->positionY = positionY;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyVisionRadiusByValue(const float value)
{
	enemyParams->visionRadius *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setAttackRadius(const float attackRadius)
{
	enemyParams->attackRadius = attackRadius;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyDamageByValue(const float value)
{
	enemyParams->damage *= value;
	return *this;
}

EnemyParams EnemyParams::Builder::build() const
{
	if(enemyParams->visionRadius < enemyParams->attackRadius)
		Log::debug("Warning: vision radius is lower attack radius");
	return *enemyParams;
}

EnemyParams::Builder::Builder(const int lvl)
{
	this->enemyParams = new EnemyParams(lvl);
}

EnemyParams::Builder::~Builder()
{
	delete this->enemyParams;
}
