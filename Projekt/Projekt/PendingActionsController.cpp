#include "stdafx.h"
#include "PendingActionsController.h"
#include "EnemyControllerImplementation.h"


void PendingActionsController::addPendingAction(std::function<void()> action, sf::Time delay)
{
	//actions->emplace_back(action, delay);
}

void PendingActionsController::addPendingAction(PendingAction* newPendingAction)
{
	actions->emplace_back(newPendingAction);
}

void PendingActionsController::checkPendingActions(const sf::Time& elapsedTime)
{
	auto it = actions->begin();
	while (it != actions->end())
	{
		auto pendingAction = *it;
		if (pendingAction->checkAction(elapsedTime))
		{
			delete pendingAction;
			it = actions->erase(it);
		}
		else
			++it;
	}
}

PendingActionsController::PendingActionsController()
{
	this->actions = new std::list<PendingAction*>();
}


PendingActionsController::~PendingActionsController()
{
	for (auto action : *actions)
		delete action;
	delete this->actions;
}
