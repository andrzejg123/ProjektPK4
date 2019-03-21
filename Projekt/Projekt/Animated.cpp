#include "stdafx.h"
#include "Animated.h"

void Animated::nextFrame()
{
	animationStep = (animationStep + 1) % animationTypesData[int(animationType)].animationFrames;
	if (autoPausing && animationType != AnimationType::Death ? animationStep == 0 : animationStep == animationTypesData[int(AnimationType::Death)].animationFrames - 1)
		animating = false;
	if(facing != Facing::None)
		sprite.setTextureRect(sf::IntRect(animationStep * frameSize.x, (int(animationType) * 4 + int(facing)) * frameSize.y, frameSize.x, frameSize.y));
	else
		sprite.setTextureRect(sf::IntRect(animationStep * frameSize.x, int(animationType) * frameSize.y, frameSize.x, frameSize.y));
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
		animationStep = animationTypesData[int(animationType)].animationFrames - 1;
		nextFrame();
	}
}

void Animated::updateAnimation(const sf::Time& elapsed)
{
	if (animating && (currentElapsed += elapsed) >= animationTypesData[int(animationType)].interval)
	{
		nextFrame();
		currentElapsed = sf::seconds(0);
	}
}

Animated::Animated()
{
}

Animated::Animated(AnimationData& animationData)
{
	this->frameSize = sf::Vector2u(animationData.frameSizeX, animationData.frameSizeY);
	this->animationTypesData = animationData.animationTypesData;
}

Animated::~Animated()
{
}
