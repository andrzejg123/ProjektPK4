#pragma once
#include "Interactive.h"
#include "Animated.h"

class Chest : public Interactive
{
public:
	Chest(sf::Texture& chestTexture, InteractionType interactionType, AnimationData& animationData);
	sf::FloatRect getFixedBounds() const;
	~Chest();
};

