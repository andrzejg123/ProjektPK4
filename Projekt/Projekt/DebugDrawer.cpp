#include "stdafx.h"
#include "DebugDrawer.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include "Enemy.h"

void DebugDrawer::toggle()
{
	isWorking = !isWorking;
}

void DebugDrawer::draw()
{
	if(isWorking)
	{
		sf::RectangleShape drawRect;
		drawRect.setOutlineThickness(1.0);
		drawRect.setFillColor(sf::Color::Transparent);

		//draw collision rects
		drawRect.setOutlineColor(sf::Color::Black);
		for(const auto collisionRect : *collisionRects)
		{
			drawRect.setPosition(collisionRect.left, collisionRect.top);
			drawRect.setSize(sf::Vector2f(collisionRect.width, collisionRect.height));
			window->draw(drawRect);
		}

		//draw enemies' fixed bounds
		drawRect.setOutlineColor(sf::Color::Red);
		const auto list = gameObjectHolder->getEnemies();
		for (auto enemy : *list)
		{
			const auto bounds = enemy->getFixedBounds();
			drawRect.setPosition(bounds.left, bounds.top);
			drawRect.setSize(sf::Vector2f(bounds.width, bounds.height));
			window->draw(drawRect);
		}

		//draw interactives' rects
		drawRect.setOutlineColor(sf::Color::Magenta);
		for (auto interactive : *gameObjectHolder->getInteractiveList())
		{
			const auto bounds = interactive->getFixedBounds();
			drawRect.setPosition(bounds.left, bounds.top);
			drawRect.setSize(sf::Vector2f(bounds.width, bounds.height));
			window->draw(drawRect);
		}

		//draw player's fixed bounds
		const auto list2 = gameObjectHolder->getFlyingObjects();
		for (auto enemy : *list2)
		{
			const auto bounds = enemy->getFixedBounds();
			drawRect.setPosition(bounds.left, bounds.top);
			drawRect.setSize(sf::Vector2f(bounds.width, bounds.height));
			window->draw(drawRect);
		}

		//draw player fixed bounds
		drawRect.setOutlineColor(sf::Color::Blue);
		const auto playerBounds = gameObjectHolder->getPlayer()->getFixedBounds();
		drawRect.setPosition(playerBounds.left, playerBounds.top);
		drawRect.setSize(sf::Vector2f(playerBounds.width, playerBounds.height));
		window->draw(drawRect);
	}
}

DebugDrawer::DebugDrawer(std::list<sf::FloatRect>* collisionRects, GameObjectsHolder* gameObjectHolder,
	sf::RenderWindow* window) : isWorking(false), collisionRects(collisionRects), gameObjectHolder(gameObjectHolder), window(window)
{
}

DebugDrawer::~DebugDrawer()
= default;
