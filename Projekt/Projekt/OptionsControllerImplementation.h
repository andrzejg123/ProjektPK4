#pragma once
#include "OptionsController.h"
#include "OptionsView.h"

class OptionsControllerImplementation : public OptionsController
{
	OptionsView* optionsView;
	unsigned int selectTextSize = 30;
	unsigned int normalTextSize = 26;

	sf::Color selectColor = sf::Color::Yellow;
	sf::Color normalColor = sf::Color::White;
	sf::Font font;

	std::vector<sf::Text*>* optionsItems;
	int currentItem = 0;

	sf::Text* createNewItem(sf::String text) const;

	sf::Sprite* background;

	void handleSelection() const;
	void repositionItems() const;
	void adjustBackgroundSize() const;

public:
	std::vector<sf::Text*>* getOptionsItems() override;
	sf::Sprite* getItemsBackground() override;
	void initializeOptions() override;
	void selectHigherItem() override;
	void selectLowerItem() override;
	void selectItem() override;
	explicit OptionsControllerImplementation(OptionsView* optionsView);
	~OptionsControllerImplementation();
};

