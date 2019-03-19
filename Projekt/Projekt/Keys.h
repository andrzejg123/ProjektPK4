#pragma once
#include <string>

//Determines type of starting configuration
enum class ProjectType
{
	Debug,
	DebugA,
	DebugS,
	Release
};

class Keys
{
public:
	static const char* version;
	static ProjectType projectType;
};

