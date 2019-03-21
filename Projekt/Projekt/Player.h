#pragma once
#include "Moveable.h"
#include "Animated.h"
#include "Damageable.h"

class Player : public Moveable, public Animated, public Damageable
{

public:
	Player();
	Player(AnimationData& animationData);
	virtual ~Player();
};

