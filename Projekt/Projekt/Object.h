#pragma once
#include <SFML/Graphics/Sprite.hpp>

enum class Facing : int
{
	Up,
	Left,
	Down,
	Right
};

class Object : public sf::Drawable
{
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	sf::Sprite sprite;
	Facing facing = Facing::Right;

public:
	sf::FloatRect getFixedBounds() const;
	void setTexture(sf::Texture &texture);
	Facing getFacing() const;
	void setFacing(Facing facing);
	Object(sf::Texture& spriteTexture);
	Object();
	~Object();
};

