#pragma once
#include "Animated.h"
#include "Moveable.h"

class FlyingObject : public Moveable, public Animated
{
	float xFactor, yFactor;
	float damage = 10;
public:
	void move(Direction direction) override;
	FlyingObject(float xFactor, float yFactor);
	
};

