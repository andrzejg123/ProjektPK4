#include "stdafx.h"
#include "Warrior.h"
#include "SoundController.h"


void Warrior::onDeath()
{
	SoundController::getInstance()->playSound(SoundIndicator::PlayerDeath);
}

void Warrior::onGetHit()
{
	SoundController::getInstance()->playSound(SoundIndicator::PlayerGetHit);
}

Warrior::Warrior(sf::Texture& playerTexture): Object(playerTexture)
{
	sprite.setTextureRect(sf::IntRect(0, int(facing) * 64, 64, 64));
}


Warrior::~Warrior()
{
}
