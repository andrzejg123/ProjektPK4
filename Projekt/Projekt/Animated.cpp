#include "stdafx.h"
#include "Animated.h"

void Animated::nextFrame()
{
	animationStep = (animationStep + 1) % animationFrames[int(animationType)];
	if (autoPausing && animationStep == 0)
		animating = false;
	sprite.setTextureRect(sf::IntRect(animationStep * 64, (int(animationType) * 4 + int(facing)) * 64, 64, 64));
}

void Animated::animate(const AnimationType animationType, bool autoPausing)
{
	this->autoPausing = autoPausing;
	this->animationType = animationType;
	animating = true;
}

void Animated::stopAnimate(AnimationType animationType)
{
	if (this->animationType == animationType)
	{
		animating = false;
		animationStep = animationFrames[int(animationType)] - 1;
		nextFrame();
	}
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
