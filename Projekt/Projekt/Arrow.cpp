#include "stdafx.h"
#include "Arrow.h"
#include "SoundController.h"

Arrow::Arrow(sf::Texture& arrowTexture, Object* caster, const sf::Vector2f factor): Object(arrowTexture), FlyingObject(factor.x, factor.y)
{
	sprite.setTextureRect(sf::IntRect(0, int(facing) * 64, 64, 64));
	sprite.setPosition(caster->getPosition().x, caster->getPosition().y);
	setSpeed(2);
	SoundController::getInstance()->playSound(SoundIndicator::ShootArrow);
}

Arrow::~Arrow()
{
}
