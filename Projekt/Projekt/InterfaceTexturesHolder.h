#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <map>

enum class InterfaceTextureIndicator
{
	MenuBackground,
	BackgroundBars,
	RedBarBig,
	BlueBarSmall,
	InteractionInfoBackground
};

class InterfaceTexturesHolder
{
	static InterfaceTexturesHolder* instance;
	std::map<InterfaceTextureIndicator, sf::Texture>* textures;
	InterfaceTexturesHolder();
	~InterfaceTexturesHolder();
public:
	static InterfaceTexturesHolder* getInstance();
	sf::Texture& getTexture(InterfaceTextureIndicator textureIndicator);
	static void clear();
};

