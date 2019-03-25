#include "stdafx.h"
#include "Arrow.h"
#include "SoundController.h"

sf::FloatRect Arrow::getFixedBounds() const
{
	sf::FloatRect fixedBounds;
	const auto defaultBounds = sprite.getGlobalBounds();
	fixedBounds.height = defaultBounds.height / 10.0f;
	fixedBounds.width = defaultBounds.width / 10.0f;
	fixedBounds.top = defaultBounds.height / 2.0f + defaultBounds.top;
	fixedBounds.left = defaultBounds.width + defaultBounds.left;
	return fixedBounds;
}

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
	sprite.setPosition(caster->getPosition().x + (caster->getBounds().width / 2), caster->getPosition().y + (caster->getBounds().height / 2));
	setSpeed(10);
	SoundController::getInstance()->playSound(SoundIndicator::ShootArrow);
}

Arrow::~Arrow()
{
}
