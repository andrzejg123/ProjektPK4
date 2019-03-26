#pragma once
#include <SFML/System/Time.hpp>
#include <functional>
#include "PendingObjectEvent.h"

class PendingAction : public PendingObjectEvent
{
	std::function<void()> action;
	sf::Time currentElapsed;
	sf::Time delay;
	bool isCancelled = false;

public:
	void cancel() override;
	bool checkAction(const sf::Time& elapsedTime);
	PendingAction(std::function<void()> action, sf::Time delay);
	~PendingAction();
};

