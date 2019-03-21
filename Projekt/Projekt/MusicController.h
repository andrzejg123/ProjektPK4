#pragma once

enum class MusicIndicator
{
	DEFAULT,
	MENU
};

//Responsible for playing music
class MusicController
{

public:
	//Plays music specified by indicator
	virtual void playMusic(MusicIndicator musicIndicator, float volume) = 0;
	virtual ~MusicController() = default;
	//Updates music, if need stops it
	virtual void updateSettings(bool shouldPlayMusic, int musicVolume) = 0;
};

