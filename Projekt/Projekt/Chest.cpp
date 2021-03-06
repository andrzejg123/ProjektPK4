#include "stdafx.h"
#include "Chest.h"

void Chest::onInteract()
{
	animate(AnimationType::ChestOpen);
}

Chest::Chest(sf::Texture& chestTexture, InteractionType interactionType, AnimationData& animationData) : Object(chestTexture), Interactive(interactionType, animationData)
{
	setFacing(Facing::None);
	sprite.setTextureRect(sf::IntRect(0, 0, animationData.frameSizeX, animationData.frameSizeY));
}

sf::FloatRect Chest::getFixedBounds() const
{
	return sprite.getGlobalBounds();
}

Chest::~Chest()
{
}
