#pragma once

struct SettingsData
{
	int musicVolume = 100;
	int soundVolume = 100;
	bool playSound = true;
	bool playMusic = true;
	bool fullscreen = true;
	int resolutionWidth = 1080;
	int resolutionHeight = 1920;
	int frameRateLimit = 60;
	bool vSyncEnabled = true;
};

class SettingsController
{
protected:
	const char* settingsFileName = "Projekt.ini";
	const char separator = '=';

	const char* settingTitle = "Game settings";

	const char* settingVideoTitle = "[Video]";
	const char* settingFullscreen = "fullscreenOn";
	const char* settingResolutionWidth = "resolutionWidth";
	const char* settingResolutionHeight = "resolutionHeight";
	const char* settingFrameRateLimit = "frameRateLimit";
	const char* settingVSyncOn = "vSyncEnabled";

	const char* settingSoundTitle = "[Sound]";
	const char* settingShouldPlaySound = "soundsOn";
	const char* settingShouldPlayMusic = "musicOn";
	const char* settingMusicVolume = "musicVolume";
	const char* settingSoundVolume = "soundVolume";

public:
	//Return settings data
	virtual SettingsData getSettingsData() = 0;
	//Updates settings data
	virtual void updateSettingsData(SettingsData settingsData) = 0;
	//Resets settings to default
	virtual void backToDefaultSettings() = 0;
	virtual ~SettingsController() = default;

};

