#pragma once
#include <SFML/Graphics/Texture.hpp>
#include "Item.h"
#include <map>

class ItemTexturesHolder
{
	static ItemTexturesHolder* instance;
	std::map<ItemIndicator, sf::Texture>* textures;
	ItemTexturesHolder();
	~ItemTexturesHolder();
public:
	sf::Texture& getTexture(ItemIndicator textureIndicator) const;
	static ItemTexturesHolder* getInstance();
	static void close();
};

