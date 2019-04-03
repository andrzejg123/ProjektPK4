#include "stdafx.h"
#include "FileNameHelper.h"

std::string FileNameHelper::getTranslationFileName(const LanguageIndicator language)
{
	const std::string prefix = "translations/";
	std::string name;
	const std::string suffix = ".txt";
	switch (language) { 
		case LanguageIndicator::English: 
			name = "english";
			break;
		case LanguageIndicator::Polish: 
			name = "polish";
			break;
		case LanguageIndicator::Silesian: 
			name = "sci";
			break;
	default: name = "en";;
	}
	return prefix + name + suffix;
}

std::string FileNameHelper::getSoundFileName(const SoundIndicator soundIndicator)
{
	const std::string prefix = "sounds/";
	std::string name;
	const std::string suffix = ".wav";
	switch (soundIndicator)
	{
	case SoundIndicator::ShootArrow:
		name = "shoot_arrow";
		break;
	case SoundIndicator::HitArrow:
		name = "hit_arrow";
		break;
	case SoundIndicator::PlayerGetHit:
		name = "player_get_hit";
		break;
	case SoundIndicator::PlayerDeath:
		name = "player_death";
		break;
	case SoundIndicator::MenuSelectItem:
		name = "menu_select_item";
		break;
	case SoundIndicator::MenuClickItem:
		name = "menu_click_item";
		break;
	default: 		
		name = "shoot_arrow";
	}
	return prefix + name + suffix;
}

std::string FileNameHelper::getMusicFileName(const MusicIndicator musicIndicator)
{
	const std::string prefix = "music/";
	std::string name;
	const std::string suffix = ".ogg";
	switch (musicIndicator)
	{
	case MusicIndicator::DEFAULT:
		name = "default";
		break;
	case MusicIndicator::MENU:
		name = "menu";
		break;
	default: 
		name = "default";
	}
	return prefix + name + suffix;
}

std::string FileNameHelper::getFontFileName(const FontIndicator fontIndicator)
{
	const std::string prefix = "fonts/";
	std::string name;
	const std::string suffix = ".ttf";
	switch (fontIndicator)
	{
	case FontIndicator::Arial:
		name = "arial";
		break;
	default:
		name = "arial";
	}
	return prefix + name + suffix;
}

std::string FileNameHelper::getEnemyFileName(const ObjectIndicator objectIndicator)
{
	const std::string prefix = "entities/enemies/";
	std::string name;
	const std::string suffix = ".txt";
	switch (objectIndicator)
	{
	case ObjectIndicator::RogueArcher:
		name = "rogue_archer";
		break;
	default:
		name = "error";
	}
	return prefix + name + suffix;
}

std::string FileNameHelper::getObjectTextureFileName(const ObjectIndicator objectIndicator)
{
	const std::string prefix = "textures/";
	std::string name;
	const std::string suffix = ".png";
	switch (objectIndicator)
	{
	case ObjectIndicator::RogueArcher:
		name = "rogue_archer";
		break;
	case ObjectIndicator::PlayerWarrior:
		name = "player_warrior";
		break;
	case ObjectIndicator::Chest:
		name = "chest";
		break;
	case ObjectIndicator::Arrow:
		name = "arrow";
		break;
	default: name = "error";
	}
	return prefix + name + suffix;
}

std::string FileNameHelper::getInterfaceTextureFileName(const InterfaceTextureIndicator textureIndicator)
{
	const std::string prefix = "textures/interface/";
	std::string name;
	const std::string suffix = ".png";
	switch (textureIndicator)
	{
	case InterfaceTextureIndicator::MenuBackground:
		name = "menu_background";
		break;
	case InterfaceTextureIndicator::BackgroundBars:
		name = "background_bars";
		break;
	case InterfaceTextureIndicator::RedBarBig:
		name = "red_bar_big";
		break;
	case InterfaceTextureIndicator::BlueBarSmall:
		name = "blue_bar_small";
		break;
	case InterfaceTextureIndicator::InteractionInfoBackground:
		name = "interaction_info_background";
		break;
	default: name = "error";
	}
	return prefix + name + suffix;
}

std::string FileNameHelper::getAnimationDataFileName(ObjectIndicator objectIndicator)
{
	const std::string prefix = "entities/animations/";
	std::string name;
	const std::string suffix = ".txt";
	switch (objectIndicator)
	{
	case ObjectIndicator::RogueArcher:
		name = "rogue_archer";
		break;
	case ObjectIndicator::PlayerWarrior:
		name = "player_warrior";
		break;
	case ObjectIndicator::Chest:
		name = "chest";
		break;

	default: name = "error";
	}
	return prefix + name + suffix;
}
