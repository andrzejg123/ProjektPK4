#include "stdafx.h"
#include "Player.h"
#include "SoundController.h"

void Player::onDeath()
{
	SoundController::getInstance()->playSound(SoundIndicator::PlayerDeath);
}

void Player::onGetHit()
{
	SoundController::getInstance()->playSound(SoundIndicator::PlayerGetHit);
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
