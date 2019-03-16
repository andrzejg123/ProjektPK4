#include "stdafx.h"
#include "MusicController.h"
#include "SoundController.h"
#include "Log.h"


void MusicController::fetchAndPlay(const MusicIndicator musicIndicator) const
{
	Log::debugS("loading new music");
	auto music = new sf::Music();
	if (music->openFromFile("music/music_" + std::to_string(int(musicIndicator)) + ".ogg"))
	{
		music->setLoop(true);
		music->setVolume(100.0f);
		(*musics)[musicIndicator] = music;
		music->play();
	}
	else
		delete music;
}

void MusicController::playMusic(const MusicIndicator musicIndicator)
{
	const auto i = musics->find(musicIndicator);
	if (i == musics->end())
	{
		SoundController::syncThread(thread);
		thread = new std::thread([=] { fetchAndPlay(musicIndicator); });
	} else 
		i->second->play();
}

MusicController::MusicController(): thread(nullptr), musics(new std::map<MusicIndicator, sf::Music*>())
{
}


MusicController::~MusicController()
{
	SoundController::syncThread(thread);
	for(auto music: *musics)
	{
		music.second->stop();
		delete music.second;
	}
	delete musics;
}
