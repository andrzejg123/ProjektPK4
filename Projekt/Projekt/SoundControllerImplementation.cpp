#include "stdafx.h"
#include "SoundControllerImplementation.h"
#include "MusicControllerImplementation.h"
#include "Log.h"
#include <SFML/Audio/Sound.hpp>
#include "SettingsReader.h"
#include "FileNameHelper.h"

SoundController* SoundControllerImplementation::instance = nullptr;

void SoundControllerImplementation::fetchAndPlay(const SoundIndicator soundIndicator) const
{
	Log::debugS("Reading new sound from file with indicator = " + std::to_string(static_cast<int>(soundIndicator)));
	readSoundMutex->lock();
	auto buffer = new sf::SoundBuffer();
	const auto check = buffer->loadFromFile(FileNameHelper::getSoundFileName(soundIndicator));
	readSoundMutex->unlock();
	if (check)
	{
		sounds->push_back(sf::Sound(*buffer));
		sounds->back().setVolume(settingsManager->getSettingsData().soundVolume);
		sounds->back().play();
		(*buffers)[soundIndicator]->soundBuffer = buffer;
		(*buffers)[soundIndicator]->loadState = LoadState::Loaded;
		Log::debugS("Finished loading new sound from file with indicator = " + std::to_string(static_cast<int>(soundIndicator)));
	}
	else
		delete buffer;
	
}

void SoundControllerImplementation::cleanUpSounds() const
{
	auto list = sounds;
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
	if (!settingsManager->getSettingsData().playSound || sounds->size() > 100)
		return;
	const auto soundData = (*buffers)[soundIndicator];
	if (soundData == nullptr)
	{
		(*buffers)[soundIndicator] = new SoundData();
		(*threads).push_back(new std::thread([=] { fetchAndPlay(soundIndicator); }));
	}
	else if(soundData->loadState == LoadState::Loaded)
	{
		sounds->push_back(sf::Sound(*soundData->soundBuffer));
		sounds->back().setVolume(settingsManager->getSettingsData().soundVolume);
		sounds->back().play();
	}
}

SoundControllerImplementation::SoundControllerImplementation()
{
	this->readSoundMutex = new std::mutex();
	this->musicController = new MusicControllerImplementation(readSoundMutex);
	this->sounds = new std::list<sf::Sound>();
	this->buffers = new std::unordered_map<SoundIndicator, SoundData*>();
	this->threads = new std::list<std::thread*>();
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
	for (auto thread : *threads)
	{
		thread->join();
		delete thread;
	}
	for (auto pair : *buffers)
		if (pair.second != nullptr)
		{
			if(pair.second->soundBuffer != nullptr)
				delete pair.second->soundBuffer;
			delete pair.second;
		}
	delete threads;
	delete buffers;
	delete sounds;
	delete musicController;
	delete settingsManager;
	delete readSoundMutex;
}
