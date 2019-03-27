#pragma once
#include "Animated.h"
#include "Moveable.h"
#include "Damageable.h"
#include "DamageHelper.h"

class FlyingObject : public Moveable, public Animated
{
protected:
	float xFactor, yFactor;
	Damage damage;
public:
	void move(Direction direction, sf::Time& elapsedTime) override;
	virtual void hitDamageable(Damageable* damageable) = 0;
	virtual void hit() = 0;
	FlyingObject(float xFactor, float yFactor, Damage& damage, Direction imageDirection);
	
};

