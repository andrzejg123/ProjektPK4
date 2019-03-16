#pragma once
#include "FlyingObject.h"

class Arrow : public FlyingObject
{
public:
	Arrow(sf::Texture& arrowTexture, Object* caster, sf::Vector2f factor);
	~Arrow();
};

