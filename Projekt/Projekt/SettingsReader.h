#pragma once
#include <vector>

struct SettingsData
{
	float musicVolume = 100;
	float soundVolume = 100;
	bool playSound = true;
	bool playMusic = true;
	bool fullscreen = true;
	int resolutionWidth = 1920;
	int resolutionHeight = 1080;
	int frameRateLimit = 60;
	bool vSyncEnabled = true;
	int language = 0;
};

class SettingsReader
{
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

	const char* settingOtherTitle = "[Other]";
	const char* settingLanguage = "language";

	bool dataLoaded = false;
	SettingsData settingsData;
	std::vector<std::string> split(const std::string& s, char delimiter) const;
	void updateSettings(SettingsData settingsData) const;

public:
	//Updates settings to its default value
	void backToDefaultSettings();
	//Reloads settings from source file
	void reloadSettings();
	//Returns currently used settings data (if settings have changed you have to use reload settings before this method)
	SettingsData getSettingsData();
	//Updates settings and source file
	void updateSettingsData(SettingsData settingsData);
};

