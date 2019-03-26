#include "stdafx.h"
#include "GameInteractionController.h"
#include "MathHelper.h"

void GameInteractionController::checkInteractions()
{
	const auto player = gameObjectsHolder->getPlayer();
	const auto playerPosition = player->getPosition();
	possibleInteractionObject = nullptr;
	auto interactiveList = gameObjectsHolder->getInteractiveList();
	auto smallestDistance = MathHelper::getDistance(playerPosition, (*interactiveList->begin())->getPosition());

	if (smallestDistance <= player->getInteractionRadius())
		possibleInteractionObject = *interactiveList->begin();

;	for(auto interactive : *gameObjectsHolder->getInteractiveList())
	{
		auto distance = MathHelper::getDistance(playerPosition, interactive->getPosition());
		if(distance < player->getInteractionRadius() && distance < smallestDistance)
		{
			smallestDistance = distance;
			possibleInteractionObject = interactive;
		}
	}

	if(possibleInteractionObject != nullptr)
	{
		auto direction = MathHelper::getDirection(playerPosition, possibleInteractionObject->getPosition());;
		if (MathHelper::directionToFacing(player->getFacing(), direction) != player->getFacing())
			possibleInteractionObject = nullptr;
	}

	gameView->setPossibleInteraction(possibleInteractionObject);
}

GameInteractionController::GameInteractionController(GameObjectsHolder* gameObjectsHolder, GameView* gameView) : gameObjectsHolder(gameObjectsHolder), gameView(gameView)
{
}

GameInteractionController::~GameInteractionController()
= default;

void GameInteractionController::handleInteraction()
{
	if(possibleInteractionObject != nullptr)
	{
		possibleInteractionObject->onInteract();
	}
}
