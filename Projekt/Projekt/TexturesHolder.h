#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>

//Symbol describing any object, it is used as a key in the holders storing objects data
enum class ObjectIndicator
{
	PlayerWarrior,
	RogueArcher,
	Chest,
	Arrow
};

class TexturesHolder
{
	static TexturesHolder* instance;
	std::map<ObjectIndicator, sf::Texture>* textures;
	TexturesHolder();
	~TexturesHolder();
	
public:
	//Returns a reference to indicated texture. If the texture is not in the map, it is loaded
	sf::Texture& getTexture(ObjectIndicator textureIndicator) const;
	static TexturesHolder* getInstance();
	static void close();
};

