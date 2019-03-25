#pragma once
#include "Moveable.h"
#include "Animated.h"
#include "Damageable.h"

class Player : public Moveable, public Animated, public Damageable
{
	float stamina = 100.0;
	float maxStamina = 100.0;
public:
	Player();
	Player(AnimationData& animationData);
	virtual ~Player();
};

