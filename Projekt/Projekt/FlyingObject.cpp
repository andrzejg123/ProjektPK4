#include "stdafx.h"
#include "FlyingObject.h"
#include "Log.h"
#include <valarray>

void FlyingObject::move(Direction direction, sf::Time& elapsedTime)
{
	Moveable::move(xFactor, yFactor, elapsedTime);
}

FlyingObject::FlyingObject(const float xFactor, const float yFactor): xFactor(xFactor), yFactor(yFactor)
{
	const auto deg = std::abs(std::atan2(xFactor, yFactor) * (180.0f / 3.14f) - 90);
	Log::debugS(std::to_string(xFactor) + "  " + std::to_string(yFactor));
	Log::debugS(std::to_string(deg));
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(deg);
}
