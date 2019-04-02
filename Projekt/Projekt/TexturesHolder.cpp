#include "stdafx.h"
#include "TexturesHolder.h"
#include "FileNameHelper.h"

TexturesHolder* TexturesHolder::instance = nullptr;

sf::Texture& TexturesHolder::getTexture(const ObjectIndicator textureIndicator) const
{
	const auto i = textures->find(textureIndicator);
	if (i == textures->end()) //texture was not loaded before
	{
		sf::Texture newTexture;
		newTexture.loadFromFile(FileNameHelper::getObjectTextureFileName(textureIndicator)); //TODO: A - throwing an exception when couldn't load
		(*textures)[textureIndicator] = newTexture;
		return (*textures)[textureIndicator];
	}
	
	return i->second; //texture was loaded, so return it
}

TexturesHolder::TexturesHolder()
{
	this->textures = new std::map<ObjectIndicator, sf::Texture>;
}

TexturesHolder* TexturesHolder::getInstance()
{
	if (instance == nullptr)
		instance = new TexturesHolder();
	return instance;
}

void TexturesHolder::close()
{
	if (instance != nullptr)
		delete instance;
}

TexturesHolder::~TexturesHolder()
{
	delete this->textures;
}
