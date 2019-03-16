#include "stdafx.h"
#include "SoundController.h"
#include "Log.h"

SoundController* SoundController::instance = nullptr;

SoundController::SoundController(): musicController(new MusicController()),
                                    playingSounds(new std::list<sf::Sound>()), sounds(new std::map<SoundIndicator, sf::SoundBuffer>()),
                                    thread(nullptr)
{
}

void SoundController::syncThread(std::thread* thread)
{
	if (thread != nullptr)
	{
		thread->join();
		delete thread;
		thread = nullptr;
	}
}

void SoundController::fetchAndPlay(SoundIndicator soundIndicator) const
{
	Log::debugS("reading new sound from file");
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile("sounds/sound_" + std::to_string(int(soundIndicator)) + ".wav"))
	{
		(*sounds)[soundIndicator] = buffer;
		playingSounds->push_back(sf::Sound((*sounds)[soundIndicator]));
		playingSounds->back().play();
	}
}

void SoundController::playSound(const SoundIndicator soundIndicator)
{
	const auto i = sounds->find(soundIndicator);
	if (i == sounds->end())
	{
		syncThread(thread);
		thread = new std::thread([=] { fetchAndPlay(soundIndicator); });
	} else {
		playingSounds->push_back(sf::Sound(i->second));
		playingSounds->back().play();
	}
}

void SoundController::playMusic(const MusicIndicator musicIndicator) const
{
	musicController->playMusic(musicIndicator);
}

SoundController* SoundController::getInstance()
{
	if (instance == nullptr)
		instance = new SoundController();
	return instance;
}

void SoundController::clearInstance()
{
	if (instance != nullptr)
		delete instance;
}

SoundController::~SoundController()
{
	syncThread(thread);
	delete sounds;
	delete playingSounds;
	delete musicController;
}
