#pragma once
#include "TexturesHolder.h"
#include "GameEntityDataHolder.h"

class InteractiveFactory
{
	TexturesHolder* gameTexturesHolder;
	GameEntityDataHolder* gameEntityDataHolder;
public:
	Interactive* create(InteractiveData& interactiveData);
	InteractiveFactory(TexturesHolder* gameTexturesHolder, GameEntityDataHolder* gameEntityDataHolder);
	~InteractiveFactory();
};

