#include "stdafx.h"
#include "MenuControllerImplementation.h"
#include "SoundController.h"
#include "Translations.h"
#include "ViewHelper.h"
#include "FileNameHelper.h"

sf::Text* MenuControllerImplementation::createNewMenuItem(const sf::String text) const
{
	auto textView = new sf::Text();
	textView->setString(text);
	textView->setFont(font);
	textView->setFillColor(normalColor);
	textView->setCharacterSize(ViewHelper::adjustFontSize(normalTextSize, menuView->getWindowSize()));
	return textView;
}

void MenuControllerImplementation::handleSelection() const
{
	const auto normal = ViewHelper::adjustFontSize(normalTextSize, menuView->getWindowSize());
	for (auto menuItem : *menuItems)
	{
		menuItem->setFillColor(normalColor);
		menuItem->setCharacterSize(normal);
	}
	auto selectedItem = menuItems->at(currentItem);
	selectedItem->setFillColor(selectColor);
	selectedItem->setCharacterSize(ViewHelper::adjustFontSize(selectTextSize, menuView->getWindowSize()));
	repositionItems();
}

void MenuControllerImplementation::repositionItems() const
{
	const auto windowSize = menuView->getWindowSize();
	const auto height = windowSize.y;
	const auto width = windowSize.x;
	const float itemsCount = menuItems->size();
	auto totalItemsSize = 0.0f;
	for (auto menuItem : *menuItems)
		totalItemsSize += menuItem->getGlobalBounds().height;
	const auto singleSpace = (height - totalItemsSize) / (10.0f + itemsCount - 1.0f);
	auto startingPosition = singleSpace * 4;
	for (auto menuItem : *menuItems)
	{
		const auto itemWidth = menuItem->getGlobalBounds().width;
		menuItem->setPosition((width - itemWidth) / 2, singleSpace + startingPosition);
		startingPosition += menuItem->getGlobalBounds().height + singleSpace;
	}
}

void MenuControllerImplementation::selectItem()
{
	SoundController::getInstance()->playSound(SoundIndicator::MenuClickItem);
	switch (currentItem)
	{
		case 0: return menuView->startNewGame();
		case 1: return menuView->loadGame();
		case 2: return menuView->showSettings();
		case 3: return menuView->showExtras();
		case 4: return menuView->hideMenu();
		default: ;
	}
}

void MenuControllerImplementation::selectHigherItem()
{
	SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
	currentItem--;
	if (currentItem < 0)
		currentItem = menuItems->size() - 1;
	handleSelection();
}

void MenuControllerImplementation::selectLowerItem()
{
	SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
	currentItem++;
	if (currentItem >= menuItems->size())
		currentItem = 0;
	handleSelection();
}

void MenuControllerImplementation::initializeMenu()
{
	SoundController::getInstance()->playMusic(MusicIndicator::MENU);
	if(font.loadFromFile(FileNameHelper::getFontFileName(FontIndicator::Arial)))
	{
		menuItems->push_back(createNewMenuItem(Translations::getText(TextId::StartNewGame)));
		menuItems->push_back(createNewMenuItem(Translations::getText(TextId::LoadGame)));
		menuItems->push_back(createNewMenuItem(Translations::getText(TextId::Settings)));
		menuItems->push_back(createNewMenuItem(Translations::getText(TextId::Extras)));
		menuItems->push_back(createNewMenuItem(Translations::getText(TextId::Quit)));
	}
	repositionItems();
	handleSelection();
}

std::vector<sf::Text*>* MenuControllerImplementation::getMenuItems()
{
	return menuItems;
}

MenuControllerImplementation::MenuControllerImplementation(MenuView* menuView)
{
	this->menuView = menuView;
	menuItems = new std::vector<sf::Text*>();
}

MenuControllerImplementation::~MenuControllerImplementation()
{
	for (auto menuItem : *menuItems)
	{
		delete menuItem;
	}
	delete menuItems;
}