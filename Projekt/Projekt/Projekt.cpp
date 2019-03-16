// Projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameViewImplementation.h"
#include <vld.h> //for detecting memory leaks with Visual Leak Detector

int main()
{
	auto gameView = new GameViewImplementation;

	gameView->displayGame();

	delete gameView;

    return 0;
}

