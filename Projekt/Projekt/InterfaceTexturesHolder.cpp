#include "stdafx.h"
#include "InterfaceTexturesHolder.h"
#include "FileNameHelper.h"

InterfaceTexturesHolder* InterfaceTexturesHolder::instance = nullptr;

InterfaceTexturesHolder::InterfaceTexturesHolder()
{
	this->textures = new std::map<InterfaceTextureIndicator, sf::Texture>();
}


InterfaceTexturesHolder::~InterfaceTexturesHolder()
{
	delete this->textures;
}

InterfaceTexturesHolder* InterfaceTexturesHolder::getInstance()
{
	if (instance == nullptr)
		instance = new InterfaceTexturesHolder();
	return instance;
}

sf::Texture& InterfaceTexturesHolder::getTexture(const InterfaceTextureIndicator textureIndicator)
{
	const auto i = textures->find(textureIndicator);
	if (i == textures->end()) //texture was not loaded before
	{
		sf::Texture newTexture;
		newTexture.loadFromFile(FileNameHelper::getInterfaceTextureFileName(textureIndicator)); //TODO: A - throwing an exception when couldn't load
		(*textures)[textureIndicator] = newTexture;
		return (*textures)[textureIndicator];
	}

	return i->second; //texture was loaded, so return it
}

void InterfaceTexturesHolder::clear()
{
	delete instance;
}
