#pragma once
#include "Moveable.h"
#include "Animated.h"
#include "Damageable.h"
#include "Weapon.h"
#include <list>
#include "Armor.h"

struct PlayerPoints
{
	float healthPoints;
	float maxHealthPoints;
	float stamina;
	float maxStamina;
};

class Player : public Moveable, public Animated, public Damageable
{
	float stamina = 100.0f;
	float maxStamina = 100.0f;
	float interactionRadius = 100.0f;
	Weapon* weapon;
	Armor* armor;
	std::list<Item*>* playerItems;
public:
	Player();
	Player(AnimationData& animationData);
	float getInteractionRadius() const;
	PlayerPoints getPlayerPoints() const;
	virtual ~Player();
};

