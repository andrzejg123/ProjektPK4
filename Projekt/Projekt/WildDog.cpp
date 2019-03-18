#include "stdafx.h"
#include "WildDog.h"
#include "DistanceHelper.h"
#include "GameTexturesHolder.h"
#include "Log.h"
#include "FlyingObjectFactory.h"

void WildDog::onDeath()
{

}

void WildDog::onGetHit()
{

}

AttackData WildDog::getAttackData()
{
	auto data = AttackData();
	data.attackType = AttackType::Arrow;
	data.damage = damage;
	return data;
}

WildDog::WildDog(sf::Texture& wildDogTexture, EnemyParams* enemyParams) : Object(wildDogTexture), Enemy(enemyParams)
{
	sprite.setTextureRect(sf::IntRect(0, int(facing) * 64, 64, 64));
}


WildDog::~WildDog()
{
}
