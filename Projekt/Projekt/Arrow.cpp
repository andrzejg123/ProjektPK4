#include "stdafx.h"
#include "Arrow.h"
#include "SoundController.h"

void Arrow::hitDamageable(Damageable* damageable)
{
	damageable->onDamage(damage);
	SoundController::getInstance()->playSound(SoundIndicator::HitArrow);
}

void Arrow::hit()
{
	SoundController::getInstance()->playSound(SoundIndicator::HitArrow);
}

Arrow::Arrow(sf::Texture& arrowTexture, Object* caster, const sf::Vector2f factor): Object(arrowTexture), FlyingObject(factor.x, factor.y)
{
	sprite.setTextureRect(sf::IntRect(0, int(facing) * 64, 64, 64));
	sprite.setPosition(caster->getPosition().x, caster->getPosition().y);
	setSpeed(120);
	SoundController::getInstance()->playSound(SoundIndicator::ShootArrow);
}

Arrow::~Arrow()
{
}
