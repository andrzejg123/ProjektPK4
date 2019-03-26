#include "stdafx.h"
#include "InteractiveFactory.h"
#include "Chest.h"


Interactive* InteractiveFactory::create(InteractiveData& interactiveData)
{
	switch(interactiveData.interactiveIndicator)
	{
	case ObjectIndicator::Chest: {
		auto chest = new Chest(gameTexturesHolder->getTexture(interactiveData.interactiveIndicator), interactiveData.interactionType,
			gameEntityDataHolder->getAnimationData(interactiveData.interactiveIndicator));
		chest->setPosition(interactiveData.position);
		return chest; 
	}
	default:;
	}
}

InteractiveFactory::InteractiveFactory(TexturesHolder* gameTexturesHolder,
	GameEntityDataHolder* gameEntityDataHolder) : gameTexturesHolder(gameTexturesHolder), gameEntityDataHolder(gameEntityDataHolder)
{
}

InteractiveFactory::~InteractiveFactory()
{
}
