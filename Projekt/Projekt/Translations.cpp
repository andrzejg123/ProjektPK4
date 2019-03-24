#include "stdafx.h"
#include "Translations.h"
#include <string>
#include <fstream>
#include <SFML/System/String.hpp>
#include <functional>
#include "FileNameHelper.h"

Translations* Translations::instance = nullptr;

Translations::Translations(const LanguageIndicator language)
{
	setLocale(language);
	translations = new std::vector<sf::String>();
}

void Translations::fetchTranslations(const LanguageIndicator language) const
{
	translations->clear();
	std::fstream file;
	file.open(FileNameHelper::getTranslationFileName(language), std::fstream::in | std::fstream::out | std::fstream::app);
	if (!file.is_open())
		return;
	std::string line;
	while (std::getline(file, line))
		translations->push_back(sf::String(line, locale));
	file.close();
}

void Translations::setLocale(const LanguageIndicator language)
{
	this->language = language;
	switch (language) {
	case LanguageIndicator::English:
		locale = std::locale("en");
		break;
	case LanguageIndicator::Polish:
		locale = std::locale("pl");
		break;
	case LanguageIndicator::Silesian:
		locale = std::locale("pl");
		break;
	default:
		locale = std::locale("en");
		break;
	}
}

void Translations::open(const LanguageIndicator language)
{
	if (instance == nullptr)
		instance = new Translations(language);
	instance->fetchTranslations(language);
}

void Translations::close()
{
	if (instance != nullptr)
		delete instance;
}

sf::String& Translations::getText(const TextId textId)
{
	const auto id = static_cast<int>(textId);
	if (instance != nullptr && instance->translations->size() > id)
		return instance->translations->at(id);
	return instance->notTranslated;
}

Translations::~Translations()
{
	delete translations;
}
