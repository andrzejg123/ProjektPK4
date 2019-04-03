#pragma once
#include "View.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Interactive.h"

class InteractionView : public View
{
	sf::RenderWindow* window;
	Interactive* doneInteraction;
public:
	void show() override;
	InteractionView(sf::RenderWindow* window, Interactive* doneInteraction);
	~InteractionView();
};

