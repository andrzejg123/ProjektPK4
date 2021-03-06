#include "stdafx.h"
#include "Object.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include "Log.h"

void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

sf::FloatRect Object::getFixedBounds() const
{
	sf::FloatRect fixedBounds;
	const auto defaultBounds = sprite.getGlobalBounds();
	fixedBounds.height = defaultBounds.height / 4.2f;
	fixedBounds.width = defaultBounds.width / 2.85f;
	fixedBounds.top = defaultBounds.top + defaultBounds.height - fixedBounds.height;
	fixedBounds.left = defaultBounds.left + (defaultBounds.width - fixedBounds.width) / 2.0f;
	return fixedBounds;
}

sf::FloatRect Object::getBounds() const
{
	return sprite.getGlobalBounds();
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

sf::Vector2f Object::getPosition() const
{
	return sprite.getPosition();
}

sf::Vector2f Object::getCenter() const
{
	auto pos = sprite.getPosition();
	pos.x += sprite.getGlobalBounds().height / 2.0f;
	pos.y += sprite.getGlobalBounds().width / 2.0f;
	return pos;
}

void Object::setPosition(const sf::Vector2f position)
{
	sprite.setPosition(position);
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
