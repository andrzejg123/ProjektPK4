#pragma once
#include "FlyingObject.h"
#include "DamageHelper.h"

class Arrow : public FlyingObject
{
public:
	sf::FloatRect getFixedBounds() const override;
	void hitDamageable(Damageable* damageable) override;
	void hit() override;
	Arrow(sf::Texture& arrowTexture, Object* caster, sf::Vector2f factor, Damage& damage);
	~Arrow();
};

