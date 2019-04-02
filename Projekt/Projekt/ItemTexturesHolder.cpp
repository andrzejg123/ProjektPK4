#include "stdafx.h"
#include "ItemTexturesHolder.h"

ItemTexturesHolder* ItemTexturesHolder::instance = nullptr;

ItemTexturesHolder::ItemTexturesHolder()
{
	this->textures = new std::map<ItemIndicator, sf::Texture>;
}

ItemTexturesHolder::~ItemTexturesHolder()
{
	delete this->textures;
}

sf::Texture& ItemTexturesHolder::getTexture(ItemIndicator textureIndicator) const
{
	const auto i = textures->find(textureIndicator);
	if (i == textures->end()) //texture was not loaded before
	{
		sf::Texture newTexture;
		newTexture.loadFromFile("textures/items/texture_" + std::to_string(int(textureIndicator)) + ".png"); //TODO: A - throwing an exception when couldn't load
		(*textures)[textureIndicator] = newTexture;
		return (*textures)[textureIndicator];
	}

	return i->second; //texture was loaded, so return it
}

ItemTexturesHolder* ItemTexturesHolder::getInstance()
{
	if (instance == nullptr)
		instance = new ItemTexturesHolder();
	return instance;
}

void ItemTexturesHolder::close()
{
	delete instance;
}
