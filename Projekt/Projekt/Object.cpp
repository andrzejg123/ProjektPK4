#include "stdafx.h"
#include "Object.h"
#include <SFML/Graphics/RenderTarget.hpp>

void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

sf::FloatRect Object::getFixedBounds() const
{
	sf::FloatRect fixedBounds;
	const auto defaultBounds = sprite.getGlobalBounds();
	fixedBounds.height = defaultBounds.height / 4.0;
	fixedBounds.width = defaultBounds.width / 2.5;
	fixedBounds.top = defaultBounds.top + defaultBounds.height - fixedBounds.height;
	fixedBounds.left = defaultBounds.left + (defaultBounds.width - fixedBounds.width) / 2.0;
	return fixedBounds;
}

void Object::setTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
}

Facing Object::getFacing() const
{
	return facing;
}

void Object::setFacing(const Facing facing)
{
	this->facing = facing;
}

Object::Object(sf::Texture& spriteTexture)
{
	sprite.setTexture(spriteTexture);
}

Object::Object()
{
	
}


Object::~Object()
{
}
