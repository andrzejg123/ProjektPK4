#pragma once
#include "Object.h"
#include <SFML/System/Time.hpp>
#include <vector>

enum class AnimationType
{
	Move,
	Attack,
	Death,
	ChestOpen = 0
};

struct AnimationTypeData
{
	sf::Time interval;
	int animationFrames;
	int autoPausingFrame;
	AnimationTypeData(const int intervalInMilliseconds, const int animationFrames, const int autoPausingFrame) : 
			interval(sf::milliseconds(intervalInMilliseconds)), animationFrames(animationFrames), autoPausingFrame(autoPausingFrame) {}
};

struct AnimationData
{
	unsigned int frameSizeX;
	unsigned int frameSizeY;
	std::vector<AnimationTypeData> animationTypesData;
};

class Animated : public virtual Object
{
	bool animating = false;
	bool autoPausing = false;
	sf::Time currentElapsed;
	int animationStep = 0;
	std::vector<AnimationTypeData> animationTypesData{};
	AnimationType animationType = AnimationType::Move;
	sf::Vector2u frameSize;
	void nextFrame();
public:
	void animate(AnimationType animationType, bool autoPausing = true);
	void stopAnimate(AnimationType animationType);
	void updateAnimation(const sf::Time &elapsed);
	Animated();
	Animated(AnimationData& animationData);
	~Animated();
};

