#pragma once
#include "Object.h"

class Damageable : public virtual Object
{
	float healthPoints = 100.0;
	float armorPoints = 100.0;
protected:	
	virtual void onGetHit() = 0;
	virtual void onDeath() = 0;
public:
	void onDamage(float damage);
	bool isDead() const;
	Damageable();
	~Damageable();
};

