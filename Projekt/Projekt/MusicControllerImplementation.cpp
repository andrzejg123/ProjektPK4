#include "stdafx.h"
#include "MusicControllerImplementation.h"
#include "Log.h"
#include "FileNameHelper.h"
#include <iostream>

void MusicControllerImplementation::fetchAndPlay(const MusicIndicator musicIndicator, const float volume) const
{
	Log::debugS("Reading new music with indicator = " + std::to_string(static_cast<int>(musicIndicator)));
	readSoundMutex->lock();
	auto music = new sf::Music();
	const auto check = music->openFromFile(FileNameHelper::getMusicFileName(musicIndicator));
	readSoundMutex->unlock();
	if (check)
	{
		music->setLoop(true);
		music->setVolume(volume);
		music->play();
		(*musics)[musicIndicator]->music = music;
		(*musics)[musicIndicator]->loadState = LoadState::Loaded;
		Log::debugS("Finished loading music with indicator = " + std::to_string(static_cast<int>(musicIndicator)));
	}
	else
		delete music;
}

void MusicControllerImplementation::stopAllMusic() const
{
	for (auto music : *musics)
		if (music.second != nullptr && music.second->music != nullptr)
			music.second->music->pause();
}

void MusicControllerImplementation::updateSettings(const bool shouldPlayMusic, const float musicVolume)
{
	if (!shouldPlayMusic)
		stopAllMusic();
	else
		for (auto music : *musics)
			if (music.second != nullptr && music.second->music != nullptr)
				music.second->music->setVolume(musicVolume);
}

void MusicControllerImplementation::playMusic(const MusicIndicator musicIndicator, const float volume)
{
	stopAllMusic();
	auto music = (*musics)[musicIndicator];
	if (music == nullptr)
	{
		(*musics)[musicIndicator] = new MusicData();
		(*threads).push_back(new std::thread([=] { fetchAndPlay(musicIndicator, volume); }));
	}
	else if(music->loadState == LoadState::Loaded)
	{
		music->music->setVolume(volume);
		music->music->play();
	}
}

MusicControllerImplementation::MusicControllerImplementation(std::mutex* mutex)
{
	this->readSoundMutex = mutex;
	this->threads = new std::list<std::thread*>();
	this->musics = new std::unordered_map<MusicIndicator, MusicData*>();
}

MusicControllerImplementation::~MusicControllerImplementation()
{
	for (auto thread : *threads)
		if (thread != nullptr)
		{
			thread->join();
			delete thread;
		}
	for (auto music : *musics)
		if (music.second != nullptr)
		{
			if(music.second->music != nullptr)
			{
				music.second->music->stop();
				delete music.second->music;
			}
			delete music.second;
		}
	delete threads;
	delete musics;
}
