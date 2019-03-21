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

Warrior::Warrior(sf::Texture& playerTexture, AnimationData& animationData) : Object(playerTexture), Player(animationData)
{
	sprite.setTextureRect(sf::IntRect(0, int(facing) * animationData.frameSizeY, animationData.frameSizeX, animationData.frameSizeY));
}

Warrior::~Warrior()
{
}
