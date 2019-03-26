#include "stdafx.h"
#include "Arrow.h"
#include "SoundController.h"

sf::FloatRect Arrow::getFixedBounds() const
{
	sf::FloatRect fixedBounds;
	const auto defaultBounds = sprite.getGlobalBounds();
	const auto centerHeight = defaultBounds.height / 2.0f;
	const auto centerWidth = defaultBounds.width / 2.0f;
	fixedBounds.height = defaultBounds.height / 10.0f;
	fixedBounds.width = defaultBounds.width / 10.0f;
	fixedBounds.top = centerHeight + defaultBounds.top + (centerHeight * yFactor);
	fixedBounds.left = centerWidth + defaultBounds.left + (centerWidth * xFactor);
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

Arrow::Arrow(sf::Texture& arrowTexture, Object* caster, const sf::Vector2f factor, const float damage): 
Object(arrowTexture), FlyingObject(factor.x, factor.y, damage, Direction::Up)
{
	sprite.setPosition(caster->getPosition().x + (caster->getBounds().width / 2), caster->getPosition().y + (caster->getBounds().height / 2));
	setSpeed(120);
	SoundController::getInstance()->playSound(SoundIndicator::ShootArrow);
}

Arrow::~Arrow()
{
}
