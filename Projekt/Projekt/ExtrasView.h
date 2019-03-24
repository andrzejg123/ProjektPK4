#pragma once
#include "View.h"
#include <SFML/Graphics.hpp>

class ExtrasView: public View
{
	float speed = 60.0f;
	sf::RenderWindow* window;
	bool shouldShowWindow = true;
	sf::Text* createNewItem(const sf::String& text) const;

	unsigned int textSize = 48;
	sf::Color color = sf::Color::White;
	sf::Font font;

	std::vector<sf::Text*>* texts;
	sf::Sprite* background;

	void repositionItems(const sf::Time& elapsedTime);
	void setInitialPosition(const sf::Vector2u& windowSize) const;

public:

	void show() override;
	explicit ExtrasView(sf::RenderWindow* window);
	~ExtrasView();
};

