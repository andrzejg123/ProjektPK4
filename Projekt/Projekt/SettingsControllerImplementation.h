#pragma once
#include "SettingsController.h"
#include <vector>

class SettingsControllerImplementation final : public SettingsController
{
	SettingsData settingsData;
	std::vector<std::string> split(const std::string& s, char delimiter) const;
	void fetchSettings();
	void updateSettings(SettingsData settingsData) const;

public:
	void backToDefaultSettings() override;
	SettingsData getSettingsData() override;
	void updateSettingsData(SettingsData settingsData) override;
	SettingsControllerImplementation();
};

