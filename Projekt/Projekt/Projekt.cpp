// Projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameViewImplementation.h"
#include <vld.h> //for detecting memory leaks with Visual Leak Detector
#include <windows.h>
#include "Keys.h"
#include "SoundController.h"
#include <conio.h>

int main()
{
	if (Keys::projectType == ProjectType::Release)
		ShowWindow(GetConsoleWindow(), SW_HIDE);

	const auto gameView = new GameViewImplementation;
	gameView->displayGame();
	delete gameView;

	SoundController::clearInstance();
	if(Keys::projectType == ProjectType::DebugS)
		_getch();
    return 0;
}

