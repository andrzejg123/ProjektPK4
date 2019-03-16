#include "stdafx.h"
#include "Player.h"


void Player::onDamage()
{
}

Player::Player()
{
}

Player::Player(sf::Texture& playerTexture) : Object(playerTexture)
{
	sprite.setTextureRect(sf::IntRect(0, int(facing) * 64, 64, 64));
}


Player::~Player()
{
}
