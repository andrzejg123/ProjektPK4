#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>

//Symbol describing any object, it is used as a key in the holders storing objects data
enum class ObjectIndicator
{
	PlayerWarrior,
	RogueArcher,
	Chest
};

class GameTexturesHolder
{
	std::map<ObjectIndicator, sf::Texture>* textures;
	
public:
	//Returns a reference to indicated texture. If the texture is not in the map, it is loaded
	sf::Texture& getTexture(ObjectIndicator textureIndicator) const;
	GameTexturesHolder();
	~GameTexturesHolder();
};

