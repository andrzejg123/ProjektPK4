#pragma once
#include "SettingsController.h"
#include <SFML/Graphics.hpp>
#include "SettingsView.h"
#include <list>
#include "SettingsManager.h"
#include "SettingsGenerator.h"

enum class SubCategoryIndicator
{
	Resolution,
	FrameRateLimit,
	VSyncEnabled,
	Fullscreen,
	GameSound,
	GameMusic,
	GameSoundVolume,
	GameMusicVolume
};

struct SubCategory
{
	sf::Text* subCategoryName;
	int currentSelection = 0;
	std::vector<const char*> subCategoriesOptionTexts;
	sf::Text* subCategoryOption;
	SubCategoryIndicator subCategoryIndicator;
};

struct Category
{
	sf::Text* categoryName;
	std::vector<SubCategory*> subCategories;
};

class SettingsControllerImplementation : public SettingsController
{
	std::vector<Category*>* categories;
	std::list<sf::Text*>* textsToDraw;
	sf::Text* restartInfo;

	SettingsView* settingsView;

	int currentItem = 0;
	int currentSubItem = 0;

	SettingsManager* settingsManager;
	SettingsGenerator* settingsGenerator;

	void unselectAll() const;
	void highlightItem(sf::Text* text) const;
	void unHighlightItem(sf::Text* text) const;
	void repositionView() const;
	void updateListToDraw() const;
	void updateSelections() const;
	void updateSettings() const;
	void addRestartInfo();

public:
	void initializeSettings() override;
	void selectHigherItem() override;
	void selectItem() override;

	void selectLeftItem() override;
	void selectLowerItem() override;
	void selectRightItem() override;
	std::list<sf::Text*>* getMenuItems() override;
	explicit SettingsControllerImplementation(SettingsView* settingsView);
	~SettingsControllerImplementation();
};

