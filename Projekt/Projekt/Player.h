#pragma once
#include "Moveable.h"
#include "Animated.h"
#include "Damageable.h"

class Player : public Moveable, public Animated, public Damageable
{
public:
	void onDamage() override;
	Player();
	Player(sf::Texture& playerTexture);
	~Player();
};

