#pragma once
#include <SFML/Graphics/Text.hpp>
#include <list>
#include <SFML/Graphics/Sprite.hpp>

enum class SubCategoryIndicator
{
	Resolution,
	FrameRateLimit,
	VSyncEnabled,
	Fullscreen,
	GameSound,
	GameMusic,
	GameSoundVolume,
	GameMusicVolume,
	Language
};

struct SubCategory
{
	sf::Text* subCategoryName;
	int currentSelection = 0;
	std::vector<sf::String> subCategoriesOptionTexts;
	sf::Text* subCategoryOption;
	SubCategoryIndicator subCategoryIndicator;
};

struct Category
{
	sf::Text* categoryName;
	std::vector<SubCategory*> subCategories;
};

class SettingsController
{
public:
	virtual sf::Sprite* getBackground() = 0;
	virtual void initializeSettings() = 0;
	virtual void selectHigherItem() = 0;
	virtual void selectLowerItem() = 0;
	virtual void selectRightItem() = 0;
	virtual void selectLeftItem() = 0;
	virtual void selectItem() = 0;
	virtual std::list<sf::Text*>* getMenuItems() = 0;
	virtual ~SettingsController() = default;
};

