#pragma once
#include <thread>
#include <SFML/Audio/SoundBuffer.hpp>
#include <map>
#include <list>
#include "MusicController.h"
#include "SoundController.h"

class SoundControllerImplementation: SoundController
{
	static SoundController* instance;
	MusicController* musicController;
	std::list<sf::Sound>* playingSounds;
	std::map<SoundIndicator, sf::SoundBuffer>* sounds;
	std::thread* thread;
	//Reads new sound from file and plays it
	void fetchAndPlay(SoundIndicator soundIndicator) const;
	SoundControllerImplementation();

public:
	static SoundController* getInstance();
	static void clearInstance();
	void playMusic(MusicIndicator musicIndicator) const override;
	void playSound(SoundIndicator soundIndicator) override;
	~SoundControllerImplementation();
};

