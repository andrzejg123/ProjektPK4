#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

Player::Player(AnimationData& animationData) : Animated(animationData)
{
}

float Player::getInteractionRadius() const
{
	return interactionRadius;
}

PlayerPoints Player::getPlayerPoints() const
{
	PlayerPoints points;
	points.healthPoints = this->healthPoints;
	points.maxHealthPoints = this->maxHealthPoints;
	points.stamina = this->stamina;
	points.maxStamina = this->maxStamina;
	return points;
}

Player::~Player()
{
}
