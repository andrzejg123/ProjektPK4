#pragma once

enum MusicIndicator
{
	DEFAULT
};

//Responsible for playing music
class MusicController
{

public:
	//Plays music specified by indicator
	virtual void playMusic(MusicIndicator musicIndicator) = 0;
	virtual ~MusicController() = default;
};

