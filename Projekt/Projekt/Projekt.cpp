// Projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vld.h> //for detecting memory leaks with Visual Leak Detector
#include "Keys.h"
#include "SoundController.h"
#include <conio.h>
#include "SettingsReader.h"
#include "Translations.h"
#include "ViewRouter.h"
#include "TexturesHolder.h"
#include "InterfaceTexturesHolder.h"
#include <windows.h>
#include <iostream>

int main()
{
	if (Keys::projectType == ProjectType::Release)
		ShowWindow(GetConsoleWindow(), SW_HIDE);

	srand(static_cast<unsigned>(time(nullptr)));

	const auto settingsReader = new SettingsReader();
	const auto settingsData = settingsReader->getSettingsData();

	Translations::open(LanguageIndicator(settingsData.language));

	auto style = sf::Style::Titlebar | sf::Style::Close;
	if (settingsData.fullscreen)
		style = style | sf::Style::Fullscreen;

	sf::RenderWindow window(sf::VideoMode(settingsData.resolutionWidth, settingsData.resolutionHeight), Keys::version, style);
	window.setFramerateLimit(settingsData.frameRateLimit);
	window.setVerticalSyncEnabled(settingsData.vSyncEnabled);

	ViewRouter::openMenu(&window);

	delete settingsReader;
	SoundController::clearInstance();
	Translations::close();
	TexturesHolder::close();
	InterfaceTexturesHolder::clear();
    return 0;
}

