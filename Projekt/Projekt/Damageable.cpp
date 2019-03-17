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

Damageable::Damageable()
{
}


Damageable::~Damageable()
{
}
