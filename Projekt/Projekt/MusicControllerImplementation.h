#pragma once
#include <SFML/Audio/Music.hpp>
#include "MusicController.h"
#include <thread>
#include <map>

class MusicControllerImplementation: public MusicController
{
	//Reads new music from file and plays it
	void fetchAndPlay(MusicIndicator musicIndicator) const;
	std::thread* thread;
	std::map<MusicIndicator, sf::Music*>* musics;
public:
	void playMusic(MusicIndicator musicIndicator) override;
	MusicControllerImplementation();
	~MusicControllerImplementation();
};

