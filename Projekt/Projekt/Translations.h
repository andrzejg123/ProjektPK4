#pragma once
#include <map>
#include <vector>
#include <xlocale>
#include <SFML/System/String.hpp>

enum class LanguageIndicator
{
	English,
	Polish,
	Silesian
};

enum class TextId
{
	GameName,
	StartNewGame,
	LoadGame,
	Settings,
	Extras,
	Quit,
	Video,
	Sound,
	Others,
	Apply,
	Cancel,
	RestoreDefaults,
	Resolution,
	FrameRateLimit,
	VSyncEnabled,
	Fullscreen,
	GameSound,
	GameMusic,
	GameSoundVolume,
	GameMusicVolume,
	Language,
	SomeChangesMayRequireRestart,
	Unlimited,
	English,
	Silesian,
	Polish,
	Yes,
	No,
	On,
	Off,
	ResumeGame,
	BackToMainMenu,
};

class Translations final
{
	LanguageIndicator language = LanguageIndicator::English;
	std::locale locale = std::locale("en");
	explicit Translations(LanguageIndicator language);
	std::vector<sf::String>* translations;
	sf::String notTranslated = sf::String("???");
	static Translations* instance;
	void fetchTranslations(LanguageIndicator language) const;
	void setLocale(LanguageIndicator language);
public:
	static void open(LanguageIndicator language);
	static void close();
	static sf::String& getText(TextId textId);
	~Translations();
};

