#include "stdafx.h"
#include "OptionsControllerImplementation.h"
#include "ViewHelper.h"
#include "FileNameHelper.h"
#include "TexturesHolder.h"

sf::Text* OptionsControllerImplementation::createNewItem(const sf::String text) const
{
	auto textView = new sf::Text();
	textView->setString(text);
	textView->setFont(font);
	textView->setFillColor(normalColor);
	textView->setCharacterSize(ViewHelper::adjustFontSize(normalTextSize, optionsView->getWindowSize()));
	return textView;
}

void OptionsControllerImplementation::handleSelection() const
{
	const auto normal = ViewHelper::adjustFontSize(normalTextSize, optionsView->getWindowSize());
	for (auto menuItem : *optionsItems)
	{
		menuItem->setFillColor(normalColor);
		menuItem->setCharacterSize(normal);
	}
	auto selectedItem = optionsItems->at(currentItem);
	selectedItem->setFillColor(selectColor);
	selectedItem->setCharacterSize(ViewHelper::adjustFontSize(selectTextSize, optionsView->getWindowSize()));
	repositionItems();
}

void OptionsControllerImplementation::repositionItems() const
{
	const auto windowSize = optionsView->getWindowSize();
	const auto height = windowSize.y;
	const auto width = windowSize.x;
	const float itemsCount = optionsItems->size();
	auto totalItemsSize = 0.0f;
	for (auto menuItem : *optionsItems)
		totalItemsSize += menuItem->getGlobalBounds().height;
	const auto singleSpace = (height - totalItemsSize) / (10.0f + itemsCount - 1.0f);
	auto startingPosition = singleSpace * 4;
	for (auto menuItem : *optionsItems)
	{
		const auto itemWidth = menuItem->getGlobalBounds().width;
		menuItem->setPosition((width - itemWidth) / 2, singleSpace + startingPosition);
		startingPosition += menuItem->getGlobalBounds().height + singleSpace;
	}
}

std::vector<sf::Text*>* OptionsControllerImplementation::getOptionsItems()
{
	return optionsItems;
}

sf::Sprite* OptionsControllerImplementation::getItemsBackground()
{
	return background;
}

void OptionsControllerImplementation::adjustBackgroundSize() const
{
	if (optionsItems->size() > 0)
	{
		const auto padding = 40.0f;
		auto maxWidth = 0.0f;
		for (auto menuItem : *optionsItems)
		{
			const auto tmp = menuItem->getGlobalBounds().width;
			if (maxWidth < tmp)
				maxWidth = tmp;
		}
		const auto windowWidth = optionsView->getWindowSize().x;
		const auto firstItem = (*optionsItems).front();
		const auto lastItem = (*optionsItems).back();
		const auto backWidth = maxWidth + (4 * padding);
		const auto backHeight = lastItem->getPosition().y + (3 * padding) - firstItem->getPosition().y;
		const auto backX = (windowWidth - maxWidth - (4 * padding)) / 2;
		const auto backY = firstItem->getPosition().y - padding;
		auto& texture = TexturesHolder::getInstance()->getTexture(ObjectIndicator::MenuBackground);
		texture.setRepeated(true);
		const auto rects = sf::IntRect(backX, backY, backWidth, backHeight);
		background->setPosition(backX, backY);
		background->setTextureRect(rects);
		background->setTexture(texture);
	}
}

void OptionsControllerImplementation::initializeOptions()
{
	SoundController::getInstance()->playMusic(MusicIndicator::MENU);
	if (font.loadFromFile(FileNameHelper::getFontFileName(FontIndicator::Arial)))
	{
		optionsItems->push_back(createNewItem(Translations::getText(TextId::ResumeGame)));
		optionsItems->push_back(createNewItem(Translations::getText(TextId::Settings)));
		optionsItems->push_back(createNewItem(Translations::getText(TextId::BackToMainMenu)));
		optionsItems->push_back(createNewItem(Translations::getText(TextId::Quit)));
	}
	handleSelection();
	adjustBackgroundSize();
}

void OptionsControllerImplementation::selectHigherItem()
{
	SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
	currentItem++;
	if (currentItem >= optionsItems->size())
		currentItem = 0;
	handleSelection();
}

void OptionsControllerImplementation::selectLowerItem()
{
	SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
	currentItem--;
	if (currentItem < 0)
		currentItem = optionsItems->size() - 1;
	handleSelection();
}

void OptionsControllerImplementation::selectItem()
{
	SoundController::getInstance()->playSound(SoundIndicator::MenuClickItem);
	switch (currentItem)
	{
	case 0: return optionsView->resumeGame();
	case 1: return optionsView->openSettings();
	case 2: return optionsView->openMainMenu();
	case 3: return optionsView->quitGame();
	default: return optionsView->resumeGame();
	}
}

OptionsControllerImplementation::OptionsControllerImplementation(OptionsView* optionsView)
{
	this->optionsView = optionsView;
	optionsItems = new std::vector<sf::Text*>();
	background = new sf::Sprite();
}

OptionsControllerImplementation::~OptionsControllerImplementation()
{
	for (auto menuItem : *optionsItems)
		delete menuItem;
	delete optionsItems;
	delete background;
}
