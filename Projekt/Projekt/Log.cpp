#include "stdafx.h"
#include "Log.h"
#include <iostream>
#include "Keys.h"

void Log::debug(const std::string log)
{
	if(Keys::projectType != ProjectType::Release)
		std::cout << log << std::endl;
}

void Log::debugA(const std::string log)
{
	if (Keys::projectType != ProjectType::DebugS)
		debug(log);
}

void Log::debugS(const std::string log)
{
	if (Keys::projectType != ProjectType::DebugA)
		debug(log);
}
