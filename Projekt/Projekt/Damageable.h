#pragma once
#include "Object.h"

class Damageable : public virtual Object
{
	float healthPoints = 100.0;
	float armorPoints = 100.0;
public:
	virtual void onDamage() = 0;
	Damageable();
	~Damageable();
};

