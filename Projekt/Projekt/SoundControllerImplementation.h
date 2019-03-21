#pragma once
#include <thread>
#include <SFML/Audio/SoundBuffer.hpp>
#include <map>
#include <list>
#include "MusicController.h"
#include "SoundController.h"
#include "SettingsReader.h"

class SoundControllerImplementation: public SoundController
{
	static SoundController* instance;
	SettingsReader* settingsManager;
	MusicController* musicController;
	std::list<sf::Sound>* playingSounds;
	std::map<SoundIndicator, sf::SoundBuffer>* sounds;
	std::thread* thread;
	//Reads new sound from file and plays it
	void fetchAndPlay(SoundIndicator soundIndicator) const;
	void cleanUpSounds() const;
	SoundControllerImplementation();

public:
	static SoundController* getInstance();
	static void clearInstance();
	void updateSettings() override;
	void playMusic(MusicIndicator musicIndicator) const override;
	void playSound(SoundIndicator soundIndicator) override;
	~SoundControllerImplementation();
};

