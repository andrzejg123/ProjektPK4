#pragma once
#include "Interactive.h"
#include "Animated.h"
#include <list>
#include "Item.h"

class Chest : public Interactive
{
	std::list<Item*>* chestItems;
public:
	void onInteract() override;
	Chest(sf::Texture& chestTexture, InteractionType interactionType, AnimationData& animationData);
	sf::FloatRect getFixedBounds() const override;
	~Chest();
};

