#include "stdafx.h"
#include "GameTexturesHolder.h"

sf::Texture& GameTexturesHolder::getTexture(const TextureIndicator textureIndicator) const
{
	const auto i = textures->find(textureIndicator);
	if (i == textures->end()) //texture was not loaded before
	{
		sf::Texture newTexture;
		newTexture.loadFromFile("textures/texture_" + std::to_string(int(textureIndicator)) + ".png"); //TODO: A - throwing an exception when couldn't load
		(*textures)[textureIndicator] = newTexture;
		return (*textures)[textureIndicator];
	}
	
	return i->second; //texture was loaded, so return it
}

GameTexturesHolder::GameTexturesHolder()
{
	this->textures = new std::map<TextureIndicator, sf::Texture>;
}

GameTexturesHolder::~GameTexturesHolder()
{
	delete this->textures;
}
