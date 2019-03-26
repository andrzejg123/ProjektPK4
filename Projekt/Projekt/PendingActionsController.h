#pragma once
#include <list>
#include "PendingAction.h"

class PendingActionsController
{
	std::list<PendingAction*>* actions;
public:
	void addPendingAction(std::function<void()> action, sf::Time delay);
	void addPendingAction(PendingAction* newPendingAction);
	void checkPendingActions(const sf::Time& elapsedTime);
	 PendingActionsController();
	~PendingActionsController();
};

