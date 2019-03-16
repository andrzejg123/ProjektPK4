#pragma once
#include "Object.h"
#include <SFML/System/Time.hpp>

enum class AnimationType
{
	Move,
	Attack,

};

//TODO: information about how many animation steps are in certain animation type, frame sizes
class Animated : public virtual Object
{
	bool animating = false;
	bool autoPausing = false;
	sf::Time currentElapsed;
	sf::Time interval = sf::milliseconds(67);
	int animationStep = 2;
	AnimationType animationType = AnimationType::Move;
	void nextFrame();
public:
	void animate(AnimationType animationType);
	void stopAnimate();
	void updateAnimation(const sf::Time &elapsed);
	Animated();
	~Animated();
};
