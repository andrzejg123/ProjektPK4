#pragma once
#include "Object.h"

class Damageable : public virtual Object
{
	
protected:
	//Called when damageable object gets hit
	virtual void onGetHit();
	//Called when damageable object dies
	virtual void onDeath();
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

