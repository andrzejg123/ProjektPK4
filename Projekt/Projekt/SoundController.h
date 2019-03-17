#pragma once
#include <map>
#include <SFML/Audio.hpp>
#include <list>
#include <thread>
#include "MusicController.h"

enum class SoundIndicator
{
	ShootArrow,
	HitArrow,
	PlayerGetHit,
	PlayerDeath,
};

//Responsible for playing any sounds
class SoundController
{
	MusicController* musicController;
	static SoundController* instance;
	SoundController();
	std::list<sf::Sound>* playingSounds;
	std::map<SoundIndicator, sf::SoundBuffer>* sounds;
	std::thread* thread;
	//Reads new sound from file and plays it
	void fetchAndPlay(SoundIndicator soundIndicator) const;
public:
	//Joins thread and removes from memory
	static void syncThread(std::thread* thread);
	//Plays sound specified by indicator
	void playSound(SoundIndicator soundIndicator);
	//Plays music specified by indicator
	void playMusic(MusicIndicator musicIndicator) const;
	//Return instance of class
	static SoundController* getInstance();
	//Clears instance
	static void clearInstance();
	~SoundController();
};

