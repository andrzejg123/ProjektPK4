#pragma once
#include "GameObjectsHolder.h"

class GameInteractionController
{
	GameObjectsHolder* gameObjectsHolder;
public:

	GameInteractionController(GameObjectsHolder* gameObjectsHolder);
	~GameInteractionController();
};

