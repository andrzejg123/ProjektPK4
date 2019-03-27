#include "stdafx.h"
#include "Damageable.h"
#include "DamageHelper.h"

void Damageable::onGetHit()
{
}

void Damageable::onDeath()
{
}

void Damageable::onDamage(Damage& damage)
{
	if (isDead())
		return;
	healthPoints -= DamageHelper::calculateDamage(damage, defense);
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
