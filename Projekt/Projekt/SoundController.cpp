#include "stdafx.h"
#include "SoundController.h"
#include "SoundControllerImplementation.h"

SoundController* SoundController::getInstance()
{
	return SoundControllerImplementation::getInstance();
}

void SoundController::clearInstance()
{
	SoundControllerImplementation::clearInstance();
}
