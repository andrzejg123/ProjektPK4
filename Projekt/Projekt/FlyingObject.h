#pragma once
#include "Animated.h"
#include "Moveable.h"
#include "Damageable.h"

class FlyingObject : public Moveable, public Animated
{
	float xFactor, yFactor;
protected:
	float damage = 20;
public:
	void move(Direction direction) override;
	virtual void hitDamageable(Damageable* damageable) = 0;
	virtual void hit() = 0;
	FlyingObject(float xFactor, float yFactor);
	
};

