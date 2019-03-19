#pragma once
#include <string>
#include <map>

class SettingsController
{
	SettingsController() = default;
	static const char* settingShouldPlaySound;
	static const char* settingShouldPlayMusic;
	static const char* settingMusicVolume;
	static const char* settingSoundVolume;
	static const char* settingFullscreen;
	static const char* settingResolutionWidth;
	static const char* settingResolutionHeight;
	static 
public:
	static std::string getString(char* key);
	static bool getBool(char* key);
	static int getInt(char* key);
	static float getFloat(char* key);
	static void open();
	static void close();
};

