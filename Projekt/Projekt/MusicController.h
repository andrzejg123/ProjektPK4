#pragma once
#include <thread>
#include <map>
#include <SFML/Audio/Music.hpp>

enum MusicIndicator
{
	DEFAULT
};

//Responsible for playing music
class MusicController
{
	//Reads new music from file and plays it
	void fetchAndPlay(MusicIndicator musicIndicator) const;
	std::thread* thread;
	std::map<MusicIndicator, sf::Music*>* musics;

public:
	//Plays music specified by indicator
	void playMusic(MusicIndicator musicIndicator);
	MusicController();
	~MusicController();
};

