#pragma once
#include "MenuController.h"
#include "MenuView.h"

class MenuControllerImplementation : public MenuController
{
	unsigned int selectTextSize = 44;
	unsigned int normalTextSize = 36;

	sf::Color selectColor = sf::Color::Yellow;
	sf::Color normalColor = sf::Color::White;
	sf::Font font;

	MenuView* menuView;
	std::vector<sf::Text*>* menuItems;
	int currentItem = 0;

	sf::Text* createNewMenuItem(sf::String text) const;
	void handleSelection() const;
	void repositionItems() const;

public:
	void selectItem() override;
	void selectHigherItem() override;
	void selectLowerItem() override;
	void initializeMenu() override;
	std::vector<sf::Text*>* getMenuItems() override;
	explicit MenuControllerImplementation(MenuView* menuView);
	~MenuControllerImplementation();
};

