#pragma once
#include <SFML/System/Vector2.hpp>
#include "SettingsReader.h"

class SettingsView
{
public:
	//Returns window size
	virtual sf::Vector2u getWindowSize() = 0;
	//Hides settings window
	virtual void hideSettings() = 0;
	//Updates window parameters (frame rate and vSync) according to settings data
	virtual void updateWindowParams(SettingsData settingsData) = 0;
	virtual ~SettingsView() = default;
};

