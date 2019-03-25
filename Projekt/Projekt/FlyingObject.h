#pragma once
#include "Animated.h"
#include "Moveable.h"
#include "Damageable.h"

class FlyingObject : public Moveable, public Animated
{
protected:
	float xFactor, yFactor;
	float damage = 1.0f;
public:
	void move(Direction direction, sf::Time& elapsedTime) override;
	virtual void hitDamageable(Damageable* damageable) = 0;
	virtual void hit() = 0;
	FlyingObject(float xFactor, float yFactor);
	
};

