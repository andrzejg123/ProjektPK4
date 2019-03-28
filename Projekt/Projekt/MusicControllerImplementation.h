#pragma once
#include <SFML/Audio/Music.hpp>
#include "MusicController.h"
#include <thread>
#include <unordered_map>
#include <mutex>
#include "SoundControllerImplementation.h"

struct MusicData
{
	LoadState loadState = LoadState::Loading;
	sf::Music* music = nullptr;
};

class MusicControllerImplementation: public MusicController
{
	void fetchAndPlay(MusicIndicator musicIndicator, float volume) const;
	std::mutex* readSoundMutex;
	std::unordered_map<MusicIndicator, MusicData*>* musics;
	std::list<std::thread*>* threads;
	void stopAllMusic() const;
public:
	void updateSettings(bool shouldPlayMusic, float musicVolume) override;
	void playMusic(MusicIndicator musicIndicator, float volume) override;
	explicit MusicControllerImplementation(std::mutex* mutex);
	~MusicControllerImplementation();
};

