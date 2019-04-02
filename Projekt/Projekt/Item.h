#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <string>

enum class ItemIndicator
{
	BasicSword,
	BasicArmor,
};

class Item
{
	std::string name;
	sf::Sprite icon;
public:
	Item();
	~Item();
};

