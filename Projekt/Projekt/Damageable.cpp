#include "stdafx.h"
#include "Damageable.h"

void Damageable::onDamage(const float damage)
{
	healthPoints -= damage;
	if (healthPoints <= 0)
		onDeath();
	else
		onGetHit();
}

bool Damageable::isDead() const
{
	return healthPoints <= 0;
}

Damageable::Damageable()
{
}


Damageable::~Damageable()
{
}
