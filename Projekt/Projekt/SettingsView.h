#pragma once
#include <SFML/System/Vector2.hpp>
#include "SettingsReader.h"

class SettingsView
{
public:
	virtual sf::Vector2u getWindowSize() = 0;
	virtual void hideSettings() = 0;
	virtual ~SettingsView() = default;
	virtual void updateWindowParams(SettingsData settingsData) = 0;
};

