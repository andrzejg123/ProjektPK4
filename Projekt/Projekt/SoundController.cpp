#include "stdafx.h"
#include "SoundController.h"
#include "SoundControllerImplementation.h"

void SoundController::syncThread(std::thread* thread)
{
	if (thread != nullptr)
	{
		thread->join();
		delete thread;
		thread = nullptr;
	}
}

SoundController* SoundController::getInstance()
{
	return SoundControllerImplementation::getInstance();
}

void SoundController::clearInstance()
{
	SoundControllerImplementation::clearInstance();
}
