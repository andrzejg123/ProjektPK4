#pragma once
#include "Moveable.h"
#include "Animated.h"
#include "Damageable.h"

struct PlayerPoints
{
	float healthPoints;
	float maxHealthPoints;
	float stamina;
	float maxStamina;
};

class Player : public Moveable, public Animated, public Damageable
{
	float stamina = 100.0;
	float maxStamina = 100.0;
	float interactionRadius = 100.0;
public:
	Player();
	Player(AnimationData& animationData);
	float getInteractionRadius() const;
	PlayerPoints getPlayerPoints() const;
	virtual ~Player();
};

