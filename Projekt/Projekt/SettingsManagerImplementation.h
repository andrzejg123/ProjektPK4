#pragma once
#include "SettingsManager.h"
#include <vector>

class SettingsManagerImplementation : public SettingsManager
{
	bool dataLoaded = false;
	SettingsData settingsData;
	std::vector<std::string> split(const std::string& s, char delimiter) const;
	void updateSettings(SettingsData settingsData) const;

public:
	void backToDefaultSettings() override;
	void reloadSettings() override;
	SettingsData getSettingsData() override;
	void updateSettingsData(SettingsData settingsData) override;
};

