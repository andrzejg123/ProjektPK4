#include "stdafx.h"
#include "GameViewInterfaceDrawer.h"
#include "InterfaceTexturesHolder.h"
#include "Log.h"
#include "FileNameHelper.h"

void GameViewInterfaceDrawer::drawInteractionInfo()
{	
	if(possibleInteraction != nullptr)
	{
		if (possibleInteractionInfoBackground.getTexture() == nullptr)
		{
			possibleInteractionInfoBackground.setTexture(InterfaceTexturesHolder::getInstance()->getTexture(InterfaceTextureIndicator::InteractionInfoBackground));
			possibleInteractionInfoBackground.setPosition(window->getSize().x / 2.0 - possibleInteractionInfoBackground.getTexture()->getSize().x / 2.0, 10.0);
		}
			
		window->draw(possibleInteractionInfoBackground);
		text.setString(sf::String("Chest"));
		auto textBounds = text.getLocalBounds();
		text.setOrigin(textBounds.width / 2.0, textBounds.height / 2.0);
		auto possibleInteractionInfoBackgroundBounds = possibleInteractionInfoBackground.getGlobalBounds();
		text.setPosition(possibleInteractionInfoBackground.getPosition().x + possibleInteractionInfoBackgroundBounds.width / 2.0, 
						possibleInteractionInfoBackground.getPosition().y + possibleInteractionInfoBackgroundBounds.height / 2.0);
		window->draw(text);
	}
}

void GameViewInterfaceDrawer::draw()
{
	window->draw(backgroundBars);
	const auto playerPoints = player->getPlayerPoints();
	if(playerPoints.healthPoints >= 0.0)
		healthBar.setScale(playerPoints.healthPoints / playerPoints.maxHealthPoints, 1.0);
	else
		healthBar.setScale(0.0, 1.0);

	if (playerPoints.stamina >= 0.0)
		staminaBar.setScale(playerPoints.stamina / playerPoints.maxStamina, 1.0);
	else
		staminaBar.setScale(0.0, 1.0);

	window->draw(healthBar);
	window->draw(staminaBar);

	drawInteractionInfo();
}

void GameViewInterfaceDrawer::setPossibleInteraction(Interactive* newPossibleInteraction)
{
	this->possibleInteraction = newPossibleInteraction;
}

GameViewInterfaceDrawer::~GameViewInterfaceDrawer()
{
}

GameViewInterfaceDrawer::GameViewInterfaceDrawer(sf::RenderWindow* window, Player* player) : window(window), player(player), possibleInteraction(nullptr)
{
	backgroundBars.setTexture(InterfaceTexturesHolder::getInstance()->getTexture(InterfaceTextureIndicator::BackgroundBars));
	backgroundBars.setPosition(10, 10);
	healthBar.setTexture(InterfaceTexturesHolder::getInstance()->getTexture(InterfaceTextureIndicator::RedBarBig));
	healthBar.setPosition(20, 20);
	staminaBar.setTexture(InterfaceTexturesHolder::getInstance()->getTexture(InterfaceTextureIndicator::BlueBarSmall));
	staminaBar.setPosition(20, 58);
	font.loadFromFile(FileNameHelper::getFontFileName(FontIndicator::Arial));
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	
}
