// Projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameViewImplementation.h"
#include <vld.h> //for detecting memory leaks with Visual Leak Detector
#include <windows.h>
#include "Keys.h"
#include "SoundController.h"
#include <conio.h>
#include "MenuViewImplementation.h"
#include <iostream>

int main()
{
	if (Keys::projectType == ProjectType::Release)
		ShowWindow(GetConsoleWindow(), SW_HIDE);

	srand(time(nullptr));

	sf::RenderWindow window(sf::VideoMode(1024, 512), Keys::version);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	const auto menuView = new MenuViewImplementation(&window);
	menuView->showMenu();
	delete menuView;

	SoundController::clearInstance();

	if(Keys::projectType == ProjectType::DebugS)
		_getch();
    return 0;
}

