#pragma once
#include "SettingsController.h"
#include <SFML/Graphics.hpp>
#include "SettingsView.h"
#include <list>
#include "SettingsReader.h"
#include "SettingsDataController.h"

class SettingsControllerImplementation : public SettingsController
{
	std::vector<Category*>* categories;
	std::list<sf::Text*>* textsToDraw;
	sf::Text* restartInfo;

	SettingsView* settingsView;

	unsigned currentItem = 0;
	unsigned currentSubItem = 0;

	sf::Sprite* background;
	SettingsReader* settingsManager;
	SettingsDataController* settingsGenerator;

	void unselectAll() const;
	void highlightItem(sf::Text* text) const;
	void unHighlightItem(sf::Text* text) const;
	void repositionView() const;
	void updateListToDraw() const;
	void updateSelections() const;
	void updateSettings() const;
	void addRestartInfo();

	bool updateItemsIndexes(int item, int subItem);
	bool updateCurrentItems(int x, int y);

public:
	void mouseLeftClick(int x, int y) override;
	void mouseRightClick(int x, int y) override;
	void mouseMove(int x, int y) override;
	sf::Sprite* getBackground() override;
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

