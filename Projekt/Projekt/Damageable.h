#pragma once
#include "Object.h"

class Damageable : public virtual Object
{
	
protected:	
	virtual void onGetHit() = 0;
	virtual void onDeath() = 0;
	float healthPoints = 100.0;
	float maxHealthPoints = 100.0;
	float armorPoints = 100.0;
public:
	void onDamage(float damage);
	bool isDead() const;
	float getMaxHealthPoints();
	float getHealthPoints();
	Damageable();
	~Damageable();
};

