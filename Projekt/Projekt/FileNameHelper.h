#pragma once
#include <string>
#include "Translations.h"
#include "SoundController.h"

enum class FontIndicator
{
	Arial
};

class FileNameHelper
{
	FileNameHelper() = default;
public:
	
	static std::string getTranslationFileName(LanguageIndicator language);
	static std::string getSoundFileName(SoundIndicator soundIndicator);
	static std::string getMusicFileName(MusicIndicator musicIndicator);
	static std::string getFontFileName(FontIndicator fontIndicator);
};

