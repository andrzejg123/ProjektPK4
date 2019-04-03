#pragma once
#include <string>
#include "Translations.h"
#include "SoundController.h"
#include "GameObjectsHolder.h"
#include "InterfaceTexturesHolder.h"

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
	static std::string getEnemyFileName(ObjectIndicator objectIndicator);
	static std::string getObjectTextureFileName(ObjectIndicator objectIndicator);
	static std::string getInterfaceTextureFileName(InterfaceTextureIndicator textureIndicator);
	static std::string getAnimationDataFileName(ObjectIndicator objectIndicator);
};

