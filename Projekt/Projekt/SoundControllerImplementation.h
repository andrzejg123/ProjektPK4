#pragma once
#include <thread>
#include <SFML/Audio/SoundBuffer.hpp>
#include <map>
#include <list>
#include "MusicController.h"
#include "SoundController.h"
#include "SettingsReader.h"
#include <unordered_map>
#include <mutex>

enum class LoadState
{
	Loaded,
	Loading
};

struct SoundData
{
	LoadState loadState = LoadState::Loading;
	sf::SoundBuffer* soundBuffer = nullptr;
};

class SoundControllerImplementation: public SoundController
{
	static SoundController* instance;
	SettingsReader* settingsManager;
	MusicController* musicController;
	std::mutex* readSoundMutex;
	std::list<sf::Sound>* sounds;
	std::unordered_map<SoundIndicator, SoundData*>* buffers;
	std::list<std::thread*>* threads;
	//Reads new sound from file and plays it
	void fetchAndPlay(SoundIndicator soundIndicator) const;
	void cleanUpSounds() const;
	SoundControllerImplementation();

public:
	static SoundController* getInstance();
	static void clearInstance();
	void updateSettings() override;
	void playMusic(MusicIndicator musicIndicator) const override;
	void playSound(SoundIndicator soundIndicator) override;
	~SoundControllerImplementation();
};

