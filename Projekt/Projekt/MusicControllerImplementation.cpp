#include "stdafx.h"
#include "MusicControllerImplementation.h"
#include "SoundController.h"
#include "Log.h"
#include <map>
#include "FileNameHelper.h"

void MusicControllerImplementation::fetchAndPlay(const MusicIndicator musicIndicator, const float volume) const
{
	Log::debugS("loading new music");
	auto music = new sf::Music();
	if (music->openFromFile(FileNameHelper::getMusicFileName(musicIndicator)))
	{
		music->setLoop(true);
		(*musics)[musicIndicator] = music;
		music->setVolume(volume);
		music->play();
	}
	else
		delete music;
}

void MusicControllerImplementation::stopAllMusic() const
{
	for (auto music : *musics)
		music.second->stop();
}

void MusicControllerImplementation::updateSettings(const bool shouldPlayMusic, const int musicVolume)
{
	if (!shouldPlayMusic)
		stopAllMusic();
	else
		for (auto music : *musics)
			music.second->setVolume(musicVolume);
}

void MusicControllerImplementation::playMusic(const MusicIndicator musicIndicator, const float volume)
{
	stopAllMusic();
	const auto i = musics->find(musicIndicator);
	if (i == musics->end())
	{
		SoundController::syncThread(thread);
		thread = new std::thread([=] { fetchAndPlay(musicIndicator, volume); });
	}
	else
	{
		i->second->setVolume(volume);
		i->second->play();
	}
}

MusicControllerImplementation::MusicControllerImplementation()
{
	this->thread = nullptr;
	this->musics = new std::map<MusicIndicator, sf::Music*>();
}

MusicControllerImplementation::~MusicControllerImplementation()
{
	SoundController::syncThread(thread);
	for (auto music : *musics)
	{
		music.second->stop();
		delete music.second;
	}
	delete musics;
}
