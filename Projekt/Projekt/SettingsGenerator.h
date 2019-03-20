#pragma once

class SettingsGenerator
{

public:
	unsigned int selectTextSize = 40;
	unsigned int normalTextSize = 36;

	sf::Color selectColor = sf::Color::Yellow;
	sf::Color normalColor = sf::Color::White;

	std::vector<bool> boolSelection = std::vector<bool>{ false, true };
	std::vector<int> volumeSelection = std::vector<int>{ 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	std::vector<int> resolutionWidthSelection = std::vector<int>{ 800, 1024, 1280, 1440, 1600, 1920, 1920 };
	std::vector<int> resolutionHeightSelection = std::vector<int>{ 600, 768, 720, 900, 900, 1080, 1200 };
	std::vector<int> frameRateSelection = std::vector<int>{ 30, 60, 120, 240, 0 };

	virtual void initialize(SettingsData settingsData) = 0;
	virtual sf::Text* createNewSettingsItem(const char* text) const = 0;
	virtual ~SettingsGenerator() = default;

};

