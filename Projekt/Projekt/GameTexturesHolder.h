#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>

//Symbol used as a key in the map storing textures
enum class TextureIndicator
{
	PlayerWarrior
};

class GameTexturesHolder
{
	std::map<TextureIndicator, sf::Texture>* textures;
	
public:
	//Returns a reference to indicated texture. If the texture is not in the map, it is loaded
	sf::Texture& getTexture(TextureIndicator textureIndicator) const;
	GameTexturesHolder();
	~GameTexturesHolder();
};

