#pragma once
#include <map>
#include <vector>

enum class Language
{
	English,
	Polish,
	Russian
};

enum class TextId
{
	Yes,
	No,
	Unlimited
};

class Translations
{
	Translations();
	std::vector<std::string>* translations;
	static Translations* instance;
	void fetchTranslations(Language language) const;
public:
	static void open(Language language);
	static void close();
	static std::string getText(TextId textId);
	~Translations();
};

