#include "stdafx.h"
#include "Damageable.h"

void Damageable::onDamage(const float damage)
{
	if (isDead())
		return;
	healthPoints -= damage;
	if (isDead())
		onDeath();
	else
		onGetHit();
}

bool Damageable::isDead() const
{
	return healthPoints <= 0;
}

float Damageable::getMaxHealthPoints()
{
	//TODO in overrides computing bonuses
	return maxHealthPoints;
}

float Damageable::getHealthPoints()
{
	return healthPoints;
}

Damageable::Damageable()
{
}


Damageable::~Damageable()
{
}
