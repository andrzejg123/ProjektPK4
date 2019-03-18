#pragma once
#include "Player.h"
class Warrior :public Player
{
protected:
	void onDeath() override;
	void onGetHit() override;
public:
	Warrior(sf::Texture& playerTexture);
	~Warrior();
};

