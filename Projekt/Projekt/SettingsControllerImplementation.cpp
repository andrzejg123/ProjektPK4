#include "stdafx.h"
#include "SettingsControllerImplementation.h"
#include "SoundController.h"
#include "SettingsReader.h"
#include "SettingsDataController.h"
#include "SettingsDataControllerImplementation.h"

void SettingsControllerImplementation::updateSettings() const
{
	SettingsData settingsData = settingsManager->getSettingsData();
	for (auto category : *categories)
	{
		for (auto subCategory : category->subCategories)
		{
			switch (subCategory->subCategoryIndicator)
			{
			case SubCategoryIndicator::Resolution:
				if (settingsGenerator->getSettingsConstance().resolutionHeightSelection.size() > subCategory->currentSelection)
				{
					settingsData.resolutionHeight = settingsGenerator->getSettingsConstance().resolutionHeightSelection.at(subCategory->currentSelection);
					settingsData.resolutionWidth = settingsGenerator->getSettingsConstance().resolutionWidthSelection.at(subCategory->currentSelection);
				}
				break;
			case SubCategoryIndicator::FrameRateLimit:
				if (settingsGenerator->getSettingsConstance().frameRateSelection.size() > subCategory->currentSelection)
					settingsData.frameRateLimit = settingsGenerator->getSettingsConstance().frameRateSelection.at(subCategory->currentSelection);
				break;
			case SubCategoryIndicator::VSyncEnabled:
				if (settingsGenerator->getSettingsConstance().boolSelection.size() > subCategory->currentSelection)
					settingsData.vSyncEnabled = settingsGenerator->getSettingsConstance().boolSelection.at(subCategory->currentSelection);
				break;
			case SubCategoryIndicator::GameSound:
				if (settingsGenerator->getSettingsConstance().boolSelection.size() > subCategory->currentSelection)
					settingsData.playSound = settingsGenerator->getSettingsConstance().boolSelection.at(subCategory->currentSelection);
				break;
			case SubCategoryIndicator::GameMusic:
				if (settingsGenerator->getSettingsConstance().boolSelection.size() > subCategory->currentSelection)
					settingsData.playMusic = settingsGenerator->getSettingsConstance().boolSelection.at(subCategory->currentSelection);
				break;
			case SubCategoryIndicator::GameSoundVolume:
				if (settingsGenerator->getSettingsConstance().volumeSelection.size() > subCategory->currentSelection)
					settingsData.soundVolume = settingsGenerator->getSettingsConstance().volumeSelection.at(subCategory->currentSelection);
				break;
			case SubCategoryIndicator::GameMusicVolume:
				if (settingsGenerator->getSettingsConstance().volumeSelection.size() > subCategory->currentSelection)
					settingsData.musicVolume = settingsGenerator->getSettingsConstance().volumeSelection.at(subCategory->currentSelection);
				break;
			case SubCategoryIndicator::Fullscreen:
				if (settingsGenerator->getSettingsConstance().boolSelection.size() > subCategory->currentSelection)
					settingsData.fullscreen = settingsGenerator->getSettingsConstance().boolSelection.at(subCategory->currentSelection);
				break;
			case SubCategoryIndicator::Language:
				if (settingsGenerator->getSettingsConstance().languageSelection.size() > subCategory->currentSelection)
					settingsData.language = settingsGenerator->getSettingsConstance().languageSelection.at(subCategory->currentSelection);
				break;
			default: ;
			}
		}
	}
	settingsManager->updateSettingsData(settingsData);
	SoundController::getInstance()->updateSettings();
}

void SettingsControllerImplementation::addRestartInfo()
{
	if(restartInfo != nullptr)
		return;
	const auto restartInfoTitle = "Some changes may require restart";
	restartInfo = settingsGenerator->createNewSettingsItem(restartInfoTitle);
	restartInfo->setFillColor(settingsGenerator->getSettingsConstance().selectColor);
	repositionView();
}

void SettingsControllerImplementation::initializeSettings()
{
	auto settings = settingsManager->getSettingsData();
	settingsGenerator->initialize(settings);
	updateSelections();
}

void SettingsControllerImplementation::unselectAll() const
{
	for (auto category : *categories)
	{
		unHighlightItem(category->categoryName);
		for (auto subCategory : category->subCategories)
			unHighlightItem(subCategory->subCategoryName);
	}
}

void SettingsControllerImplementation::highlightItem(sf::Text* text) const
{
	text->setFillColor(settingsGenerator->getSettingsConstance().selectColor);
	text->setCharacterSize(settingsGenerator->getSettingsConstance().selectTextSize);
}

void SettingsControllerImplementation::unHighlightItem(sf::Text* text) const
{
	text->setFillColor(settingsGenerator->getSettingsConstance().normalColor);
	text->setCharacterSize(settingsGenerator->getSettingsConstance().normalTextSize);
}

void SettingsControllerImplementation::repositionView() const
{
	const auto windowSize = settingsView->getWindowSize();
	const auto horizontalMargin = 30.0f;
	const auto verticalMargin = 30.0f;
	if (restartInfo != nullptr)
		restartInfo->setPosition( 
		(windowSize.x - restartInfo->getGlobalBounds().width) / 2, 
			windowSize.y - restartInfo->getGlobalBounds().height - verticalMargin);
	auto categoryOutline = horizontalMargin;
	for (auto category : *categories)
	{
		category->categoryName->setPosition(categoryOutline, verticalMargin * 2);
		categoryOutline += category->categoryName->getGlobalBounds().width + horizontalMargin;
		auto subCategoryOutline = (verticalMargin * 4) + category->categoryName->getGlobalBounds().height;
		for (auto subCategory : category->subCategories)
		{
			subCategory->subCategoryOption->setString(subCategory->subCategoriesOptionTexts.at(subCategory->currentSelection));
			subCategory->subCategoryName->setPosition(horizontalMargin, subCategoryOutline);
			subCategory->subCategoryOption->setPosition(windowSize.x - subCategory->subCategoryOption->getGlobalBounds().width - horizontalMargin, subCategoryOutline);
			subCategoryOutline += subCategory->subCategoryName->getGlobalBounds().height + horizontalMargin;
		}
	}
}

void SettingsControllerImplementation::updateListToDraw() const
{
	textsToDraw->clear();
	if (restartInfo != nullptr)
		textsToDraw->push_back(restartInfo);
	for (auto category : *categories)
		textsToDraw->push_back(category->categoryName);
	for (auto subCategory : categories->at(currentItem)->subCategories)
	{
		textsToDraw->push_back(subCategory->subCategoryName);
		textsToDraw->push_back(subCategory->subCategoryOption);
	}
}

void SettingsControllerImplementation::updateSelections() const
{
	unselectAll();
	auto category = categories->at(currentItem);
	if (currentSubItem == 0)
		highlightItem(category->categoryName);
	else
		highlightItem(category->subCategories.at(currentSubItem - 1)->subCategoryName);
	updateListToDraw();
	repositionView();
}

void SettingsControllerImplementation::selectHigherItem()
{
	if (currentSubItem != 0)
	{
		SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
		currentSubItem--;
	}
	updateSelections();
}

void SettingsControllerImplementation::selectItem()
{
	if(currentSubItem == 0)
	{
		if(currentItem == categories->size() - 3)
		{
			updateSettings();
			settingsView->hideSettings();
			SoundController::getInstance()->playSound(SoundIndicator::MenuClickItem);
		}
		if(currentItem == categories->size() - 2)
		{
			settingsView->hideSettings();
			SoundController::getInstance()->playSound(SoundIndicator::MenuClickItem);
		}
		if (currentItem == categories->size() - 1)
		{
			settingsManager->backToDefaultSettings();
			SoundController::getInstance()->updateSettings();
			SoundController::getInstance()->playSound(SoundIndicator::MenuClickItem);
			settingsView->hideSettings();
		}
	}
}

void SettingsControllerImplementation::selectLeftItem()
{
	if (currentSubItem == 0)
	{
		if (currentItem != 0)
		{
			currentItem--;
			SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
		}
	}
	else
	{
		if (categories->at(currentItem)->subCategories.at(currentSubItem - 1)->currentSelection != 0)
		{
			categories->at(currentItem)->subCategories.at(currentSubItem - 1)->currentSelection--;
			SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
			if (currentItem == 0 || currentItem == 2)
				addRestartInfo();
		}	
	}
	updateSelections();
}

void SettingsControllerImplementation::selectLowerItem()
{
	if (currentSubItem < categories->at(currentItem)->subCategories.size())
	{
		SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
		currentSubItem++;
	}
	updateSelections();
}

void SettingsControllerImplementation::selectRightItem()
{
	if(currentSubItem == 0)
	{
		if (currentItem < categories->size() - 1)
		{
			currentItem++;
			SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
		}
	} else
	{
		const auto subCategory = categories->at(currentItem)->subCategories.at(currentSubItem - 1);
		if (subCategory->currentSelection < subCategory->subCategoriesOptionTexts.size() - 1)
		{
			SoundController::getInstance()->playSound(SoundIndicator::MenuSelectItem);
			categories->at(currentItem)->subCategories.at(currentSubItem - 1)->currentSelection++;
			if(currentItem == 0 || currentItem == 2)
				addRestartInfo();
		}
	}
	updateSelections();
}

std::list<sf::Text*>* SettingsControllerImplementation::getMenuItems()
{
	return textsToDraw;
}

SettingsControllerImplementation::SettingsControllerImplementation(SettingsView* settingsView)
{
	this->settingsView = settingsView;
	this->categories = new std::vector<Category*>();
	this->textsToDraw = new std::list<sf::Text*>();
	this->settingsManager = new SettingsReader();
	this->settingsManager->reloadSettings();
	this->settingsGenerator = new SettingsDataControllerImplementation(categories);
	this->restartInfo = nullptr;
}

SettingsControllerImplementation::~SettingsControllerImplementation()
{
	for (auto category : *categories)
	{
		delete category->categoryName;
		for (auto subCategory : category->subCategories)
		{
			delete subCategory->subCategoryName;
			delete subCategory->subCategoryOption;
			delete subCategory;
		}
		delete category;
	}
	delete categories;
	delete textsToDraw;
	delete settingsManager;
	delete settingsGenerator;
	delete restartInfo;
}
