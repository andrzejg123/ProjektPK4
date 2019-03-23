#pragma once
#include "SettingsView.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "SettingsController.h"
#include "View.h"

class SettingsViewImplementation : public SettingsView, public View
{
	sf::RenderWindow* window;
	SettingsController* settingsController;
	bool shouldShowSettings = true;
public:
	void updateWindowParams(SettingsData settingsData) override;
	sf::Vector2u getWindowSize() override;
	void show() override;
	void hideSettings() override;
	explicit SettingsViewImplementation(sf::RenderWindow* window);
	~SettingsViewImplementation();
};

