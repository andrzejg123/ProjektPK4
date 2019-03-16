#pragma once
#include <string>

class Log
{
public:
	//Logs data globally for both developers
	static void debug(std::string log);
	//Logs data for Andrzej
	static void debugA(std::string log);
	//Logs data for Szymon
	static void debugS(std::string log);
};

