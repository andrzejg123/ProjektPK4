#pragma once
#include "OptionsController.h"
#include "OptionsView.h"

class OptionsControllerImplementation : public OptionsController
{
	OptionsView* optionsView;
	unsigned int selectTextSize = 30;
	unsigned int normalTextSize = 26;
	const float backgroundPadding = 40.0f;
	const float borderThickness = 2.0f;

	sf::Color borderColor = sf::Color::Yellow;
	sf::Color selectColor = sf::Color::Yellow;
	sf::Color normalColor = sf::Color::White;
	sf::Font font;

	std::vector<sf::Text*>* optionsItems;
	int currentItem = 0;

	sf::Text* createNewItem(const sf::String& text) const;

	sf::RectangleShape* backgroundBorders;
	sf::Sprite* background;

	void handleSelection() const;
	void repositionItems() const;
	void adjustBackgroundSize() const;
	int getNumberOfItem(float x, float y) const;

public:
	void mouseClick(float x, float y) override;
	void mouseMove(float x, float y) override;
	std::vector<sf::Text*>* getOptionsItems() override;
	sf::RectangleShape* getBackgroundBorders() override;
	sf::Sprite* getItemsBackground() override;
	void initializeOptions() override;
	void selectHigherItem() override;
	void selectLowerItem() override;
	void selectItem() override;
	explicit OptionsControllerImplementation(OptionsView* optionsView);
	~OptionsControllerImplementation();
};

