#include "stdafx.h"
#include "SettingsReader.h"
#include <string>
#include <sstream>
#include "Log.h"
#include <fstream>
#include <iostream>

SettingsData SettingsReader::getSettingsData()
{
	if (!dataLoaded)
		reloadSettings();
	return settingsData;
}

void SettingsReader::updateSettingsData(const SettingsData settingsData)
{
	this->settingsData = settingsData;
	updateSettings(settingsData);
}

void SettingsReader::backToDefaultSettings()
{
	Log::debugS("Generating default settings");
	const SettingsData settingsData;
	this->settingsData = settingsData;
	updateSettings(settingsData);
}

void SettingsReader::reloadSettings()
{
	dataLoaded = true;
	std::fstream file;
	file.open(settingsFileName, std::fstream::in | std::fstream::out | std::fstream::app);
	if (!file.is_open())
		return;
	SettingsData settingsData;
	std::string line;
	auto changeCounter = 0;
	while (std::getline(file, line))
	{
		auto separated = split(line, separator);
		if (separated.size() == 2)
		{
			changeCounter++;
			auto key = separated.at(0);
			try
			{
				const auto value = std::stoi(separated.at(1));
				if (value < 0)
					throw std::bad_cast();
				if (key._Equal(settingFullscreen))
					settingsData.fullscreen = value;
				else if (key._Equal(settingResolutionHeight))
					settingsData.resolutionHeight = value;
				else if (key._Equal(settingResolutionWidth))
					settingsData.resolutionWidth = value;
				else if (key._Equal(settingMusicVolume))
					settingsData.musicVolume = static_cast<float>(value);
				else if (key._Equal(settingSoundVolume))
					settingsData.soundVolume = static_cast<float>(value);
				else if (key._Equal(settingShouldPlayMusic))
					settingsData.playMusic = value;
				else if (key._Equal(settingShouldPlaySound))
					settingsData.playSound = value;
				else if (key._Equal(settingFrameRateLimit))
					settingsData.frameRateLimit = value;
				else if (key._Equal(settingVSyncOn))
					settingsData.vSyncEnabled = value;
				else if (key._Equal(settingLanguage))
					settingsData.language = value;
				else changeCounter--;
			}
			catch (...)
			{
				Log::debug("Settings invalid argument for key: " + key);
			}
		}
	}
	if (changeCounter == 0)
		backToDefaultSettings();
	else
		this->settingsData = settingsData;
	file.close();
}

std::vector<std::string> SettingsReader::split(const std::string& s, const char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

void SettingsReader::updateSettings(const SettingsData settingsData) const
{
	std::fstream file;
	file.open(settingsFileName, std::ios::out | std::ios::trunc);
	if (!file.is_open())
		return;
	file << settingTitle << "\n";
	file << "\n" << settingVideoTitle << "\n";
	file << settingFullscreen << separator << settingsData.fullscreen << "\n";
	file << settingResolutionHeight << separator << settingsData.resolutionHeight << "\n";
	file << settingResolutionWidth << separator << settingsData.resolutionWidth << "\n";
	file << settingFrameRateLimit << separator << settingsData.frameRateLimit << "\n";
	file << settingVSyncOn << separator << settingsData.vSyncEnabled << "\n";
	file << "\n" << settingSoundTitle << "\n";
	file << settingSoundVolume << separator << settingsData.soundVolume << "\n";
	file << settingMusicVolume << separator << settingsData.musicVolume << "\n";
	file << settingShouldPlaySound << separator << settingsData.playSound << "\n";
	file << settingShouldPlayMusic << separator << settingsData.playMusic << "\n";
	file << "\n" << settingOtherTitle << "\n";
	file << settingLanguage << separator << settingsData.language << "\n";
	file.close();
}


