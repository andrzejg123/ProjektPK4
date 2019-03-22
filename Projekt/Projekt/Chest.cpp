#include "stdafx.h"
#include "Chest.h"

Chest::Chest(sf::Texture& chestTexture, InteractionType interactionType, AnimationData& animationData) : Object(chestTexture), Interactive(interactionType, animationData)
{
	setFacing(Facing::None);
	sprite.setTextureRect(sf::IntRect(0, 0, animationData.frameSizeX, animationData.frameSizeY));
}

Chest::~Chest()
{
}
