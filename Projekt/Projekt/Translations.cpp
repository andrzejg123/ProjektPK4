#include "stdafx.h"
#include "Translations.h"
#include <string>
#include <fstream>

Translations* Translations::instance = nullptr;

void Translations::fetchTranslations(Language language) const
{
	const auto languageId = static_cast<int>(language);
	translations->clear();
	std::fstream file;
	file.open("translations/translation_" + std::to_string(languageId), std::fstream::in | std::fstream::out | std::fstream::app);
	if (!file.is_open())
		return;
	std::string line;
	while (std::getline(file, line))
		translations->push_back(line);
	file.close();
}

void Translations::open(const Language language)
{
	if (instance == nullptr)
		instance = new Translations();
	instance->fetchTranslations(language);
}

void Translations::close()
{
	if (instance != nullptr)
		delete instance;
}

std::string Translations::getText(const TextId textId)
{
	const auto id = static_cast<int>(textId);
	if (instance != nullptr && instance->translations->size() > id)
		return instance->translations->at(id);
	return " ";
}

Translations::Translations()
{
	translations = new std::vector<std::string>();
}

Translations::~Translations()
{
	delete translations;
}
