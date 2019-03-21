#pragma once
#include <SFML/Audio/Music.hpp>
#include "MusicController.h"
#include <thread>
#include <map>

struct SettingsData;

class MusicControllerImplementation: public MusicController
{
	//Reads new music from file and plays it
	void fetchAndPlay(MusicIndicator musicIndicator, float volume) const;
	std::thread* thread;
	std::map<MusicIndicator, sf::Music*>* musics;
	void stopAllMusic() const;
public:
	void updateSettings(bool shouldPlayMusic, int musicVolume) override;
	void playMusic(MusicIndicator musicIndicator, float volume) override;
	MusicControllerImplementation();
	~MusicControllerImplementation();
};

