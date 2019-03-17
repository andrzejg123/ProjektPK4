#pragma once
#include "Moveable.h"
#include "Animated.h"
#include "Damageable.h"

class Player : public Moveable, public Animated, public Damageable
{
protected:
	void onDeath() override;
	void onGetHit() override;
public:
	Player(sf::Texture& playerTexture);
	~Player();
};

