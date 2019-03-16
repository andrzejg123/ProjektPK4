#include "stdafx.h"
#include "Animated.h"

void Animated::nextFrame()
{
	animationStep = (animationStep + 1) % 9; 
	sprite.setTextureRect(sf::IntRect(animationStep * 64, (int(animationType) * 4 + int(facing)) * 64, 64, 64));
}

void Animated::animate(const AnimationType animationType)
{
	this->animationType = animationType;
	animating = true;
}

void Animated::stopAnimate()
{
	animating = false;
	animationStep = 8;
	nextFrame();
}

void Animated::updateAnimation(const sf::Time& elapsed)
{
	if (animating && (currentElapsed += elapsed) >= interval)
	{
		nextFrame();
		currentElapsed = sf::seconds(0);
	}
}

Animated::Animated()
{
	
}


Animated::~Animated()
{
}