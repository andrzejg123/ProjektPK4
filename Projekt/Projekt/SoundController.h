#pragma once
#include <thread>
#include "MusicController.h"

enum class SoundIndicator
{
	ShootArrow,
	HitArrow,
	PlayerGetHit,
	PlayerDeath,
	MenuSelectItem,
	MenuClickItem,
};

//Responsible for playing any sounds
class SoundController
{

public:
	//Update sound settings
	virtual void updateSettings() = 0;
	//Joins thread and removes from memory
	static void syncThread(std::thread* thread);
	//Plays sound specified by indicator
	virtual void playSound(SoundIndicator soundIndicator) = 0;
	//Plays music specified by indicator
	virtual void playMusic(MusicIndicator musicIndicator) const = 0;
	//Return instance of class
	static SoundController* getInstance();
	//Clears instance
	static void clearInstance();
	virtual ~SoundController() = default;
};

