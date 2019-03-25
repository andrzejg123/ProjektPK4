#pragma once
#include "Object.h"
#include "Animated.h"
#include "TexturesHolder.h"

enum class InteractionType
{
	TreasureOpen,
	TreasureClosed,
	Speak,
	LeaveLocation
};

struct InteractiveData
{
	ObjectIndicator interactiveIndicator;
	InteractionType interactionType;
	sf::Vector2f position;
	InteractiveData(const ObjectIndicator interactiveIndicator, const InteractionType interactionType, const sf::Vector2f position) : 
					interactiveIndicator(interactiveIndicator), interactionType(interactionType), position(position) {}
};

class Interactive : public Animated
{
	InteractionType interactionType;
public:
	virtual void onInteract() = 0;
	Interactive(InteractionType interactionType, AnimationData& animationData);
	~Interactive();
};

