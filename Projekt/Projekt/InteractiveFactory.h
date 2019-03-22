#pragma once
#include "GameTexturesHolder.h"
#include "GameEntityDataHolder.h"

class InteractiveFactory
{
	GameTexturesHolder* gameTexturesHolder;
	GameEntityDataHolder* gameEntityDataHolder;
public:
	Interactive* create(InteractiveData& interactiveData);
	InteractiveFactory(GameTexturesHolder* gameTexturesHolder, GameEntityDataHolder* gameEntityDataHolder);
	~InteractiveFactory();
};

