#include "stdafx.h"
#include "SoundControllerImplementation.h"
#include "MusicControllerImplementation.h"
#include "Log.h"
#include <SFML/Audio/Sound.hpp>

SoundController* SoundControllerImplementation::instance = nullptr;

void SoundControllerImplementation::fetchAndPlay(SoundIndicator soundIndicator) const
{
	Log::debugS("reading new sound from file");
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile("sounds/sound_" + std::to_string(int(soundIndicator)) + ".wav"))
	{
		(*sounds)[soundIndicator ] = buffer;
		playingSounds->push_back(sf::Sound((*sounds)[soundIndicator]));
		playingSounds->back().play();
	}
}

void SoundControllerImplementation::playMusic(const MusicIndicator musicIndicator) const
{
	musicController->playMusic(musicIndicator);
}

void SoundControllerImplementation::playSound(const SoundIndicator soundIndicator)
{
	const auto i = sounds->find(soundIndicator);
	if (i == sounds->end())
	{
		syncThread(thread);
		thread = new std::thread([=] { fetchAndPlay(soundIndicator); });
	}
	else {
		playingSounds->push_back(sf::Sound(i->second));
		playingSounds->back().play();
	}
}

SoundControllerImplementation::SoundControllerImplementation()
{
	this->musicController = new MusicControllerImplementation();
	this->playingSounds = new std::list<sf::Sound>();
	this->sounds = new std::map<SoundIndicator, sf::SoundBuffer>();
	this->thread = nullptr;
}

SoundController* SoundControllerImplementation::getInstance()
{
	if (instance == nullptr)
		instance = new SoundControllerImplementation();
	return instance;
}

void SoundControllerImplementation::clearInstance()
{
	if (instance != nullptr)
		delete instance;
}

SoundControllerImplementation::~SoundControllerImplementation()
{
	syncThread(thread);
	delete sounds;
	delete playingSounds;
	delete musicController;
}
