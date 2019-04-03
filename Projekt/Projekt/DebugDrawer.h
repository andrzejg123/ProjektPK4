#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include "GameObjectsHolder.h"
#include "Drawer.h"

class DebugDrawer : public Drawer
{
	bool isWorking;
	std::list<sf::FloatRect>* collisionRects;
	GameObjectsHolder* gameObjectHolder;
	sf::RenderWindow* window;
public:
	void toggle();
	void draw() override;
	DebugDrawer(std::list<sf::FloatRect>* collisionRects, GameObjectsHolder* gameObjectHolder, sf::RenderWindow* window);
	~DebugDrawer();
};

