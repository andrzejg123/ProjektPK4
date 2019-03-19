#pragma once
#include <SFML/Graphics/Sprite.hpp>

enum class Facing : int
{
	Up,
	Left,
	Down,
	Right,
	None
};

class Object : public sf::Drawable
{
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	sf::Sprite sprite;
	Facing facing = Facing::Right;

public:
	sf::FloatRect getFixedBounds() const;
	sf::FloatRect getBounds() const;
	void setTexture(sf::Texture &texture);
	Facing getFacing() const;
	void setFacing(Facing facing);
	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f position);
	Object(sf::Texture& spriteTexture);
	Object();
	~Object();
};

