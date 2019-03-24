#pragma once
#include "MenuController.h"
#include "MenuView.h"
#include "TexturesHolder.h"

class MenuControllerImplementation : public MenuController
{
	unsigned int gameNameTextSize = 48;
	unsigned int selectTextSize = 44;
	unsigned int normalTextSize = 36;

	sf::Color selectColor = sf::Color::Yellow;
	sf::Color normalColor = sf::Color::White;
	sf::Font font;

	MenuView* menuView;
	std::vector<sf::Text*>* menuItems;
	sf::Text* gameName;
	int currentItem = 0;
	sf::Sprite* background;

	sf::Text* createNewMenuItem(const sf::String& text) const;
	void handleSelection() const;
	void repositionItems() const;
	int getNumberOfItem(float x, float y) const;

public:
	void mouseClick(float x, float y) override;
	void mouseMove(float x, float y) override;
	sf::Text* getGameName() override;
	sf::Sprite* getBackground() override;
	void selectItem() override;
	void selectHigherItem() override;
	void selectLowerItem() override;
	void initializeMenu() override;
	std::vector<sf::Text*>* getMenuItems() override;
	explicit MenuControllerImplementation(MenuView* menuView);
	~MenuControllerImplementation();
};

