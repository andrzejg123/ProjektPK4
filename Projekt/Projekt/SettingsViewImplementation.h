#pragma once
#include "SettingsView.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "SettingsController.h"

class SettingsViewImplementation : public SettingsView
{
	sf::RenderWindow* window;
	SettingsController* settingsController;
	bool shouldShowSettings = true;
public:
	void updateWindowParams(SettingsData settingsData) override;
	sf::Vector2u getWindowSize() override;
	void showSettings() override;
	void hideSettings() override;
	explicit SettingsViewImplementation(sf::RenderWindow* window);
	~SettingsViewImplementation();
};

