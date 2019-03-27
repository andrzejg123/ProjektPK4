#include "stdafx.h"
#include "PendingAction.h"
#include "Log.h"


void PendingAction::cancel()
{
	isCancelled = true;
}

bool PendingAction::checkAction(const sf::Time& elapsedTime)
{
	if (isCancelled)
	{
		Log::debugA("the world is saved");
		return true;
	}
		
	
	if((currentElapsed += elapsedTime) >= delay)
	{
		action();
		return true;
	}

	return false;
}

PendingAction::PendingAction(std::function<void()> action, sf::Time delay) : action(action), delay(delay)
{
}

PendingAction::~PendingAction()
{
}
