#include "stdafx.h"
#include "SoundControllerImplementation.h"
#include "MusicControllerImplementation.h"
#include "Log.h"
#include <SFML/Audio/Sound.hpp>
#include <iostream>
#include "SettingsReader.h"

SoundController* SoundControllerImplementation::instance = nullptr;

void SoundControllerImplementation::fetchAndPlay(SoundIndicator soundIndicator) const
{
	Log::debugS("reading new sound from file");
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile("sounds/sound_" + std::to_string(int(soundIndicator)) + ".wav"))
	{
		(*sounds)[soundIndicator] = buffer;
		playingSounds->push_back(sf::Sound((*sounds)[soundIndicator]));
		playingSounds->back().setVolume(settingsManager->getSettingsData().soundVolume);
		playingSounds->back().play();
	}
}

void SoundControllerImplementation::cleanUpSounds() const
{
	auto list = playingSounds;
	auto it = list->begin();
	while (it != list->end()) {
		if (it->getStatus() != sf::Sound::Playing)
		{
			it->stop();
			it = list->erase(it);
		}
		else
			++it;
	}
}

void SoundControllerImplementation::playMusic(const MusicIndicator musicIndicator) const
{
	if (settingsManager->getSettingsData().playMusic)
		musicController->playMusic(musicIndicator, settingsManager->getSettingsData().musicVolume);
}

void SoundControllerImplementation::playSound(const SoundIndicator soundIndicator)
{
	cleanUpSounds();
	if (!settingsManager->getSettingsData().playSound)
		return;
	const auto i = sounds->find(soundIndicator);
	if (i == sounds->end())
	{
		syncThread(thread);
		thread = new std::thread([=] { fetchAndPlay(soundIndicator); });
	}
	else {
		playingSounds->push_back(sf::Sound(i->second));
		playingSounds->back().setVolume(settingsManager->getSettingsData().soundVolume);
		playingSounds->back().play();
	}
}

SoundControllerImplementation::SoundControllerImplementation()
{
	this->musicController = new MusicControllerImplementation();
	this->playingSounds = new std::list<sf::Sound>();
	this->sounds = new std::map<SoundIndicator, sf::SoundBuffer>();
	this->thread = nullptr;
	settingsManager = new SettingsReader();
	settingsManager->reloadSettings();
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

void SoundControllerImplementation::updateSettings()
{
	settingsManager->reloadSettings();
	musicController->updateSettings(settingsManager->getSettingsData().playMusic, settingsManager->getSettingsData().musicVolume);
}

SoundControllerImplementation::~SoundControllerImplementation()
{
	syncThread(thread);
	delete sounds;
	delete playingSounds;
	delete musicController;
	delete settingsManager;
}
