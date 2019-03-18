#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include "GameObjectHolder.h"

class DebugDrawer
{
	bool isWorking;
public:
	void toggle();
	void draw(std::list<sf::FloatRect>* collisionRects, GameObjectHolder* gameObjectHolder, sf::RenderWindow* window);
	DebugDrawer();
	~DebugDrawer();
};

