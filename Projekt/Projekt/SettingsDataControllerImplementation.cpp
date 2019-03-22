#include "stdafx.h"
#include "SettingsDataControllerImplementation.h"
#include <iostream>
#include "Translations.h"
#include "ViewHelper.h"
#include "FileNameHelper.h"

void SettingsDataControllerImplementation::initialize(SettingsData& settingsData)
{
	if (font.loadFromFile(FileNameHelper::getFontFileName(FontIndicator::Arial)))
	{
		generateVideoSettings(settingsData);
		generateSoundSettings(settingsData);
		generateOtherSettings(settingsData);
		generateControlSettings();
	}
}

int SettingsDataControllerImplementation::checkBoolSelection(const std::vector<bool>& optionsSelections, const bool settingsOption)
{
	auto index = 0;
	for (auto selection : optionsSelections)
	{
		if (selection == settingsOption)
			return index;
		index++;
	}
	return 0;
}

int SettingsDataControllerImplementation::checkIntSelection(std::vector<sf::String>& options, const std::vector<int>& optionsSelections,
                                                       const int settingsOption) const
{
	auto index = 0;
	for (auto selection : optionsSelections)
	{
		if (selection == settingsOption)
			return index;
		index++;
	}
	options.push_back(std::to_string(settingsOption));
	return options.size() - 1;
}

int SettingsDataControllerImplementation::checkIntSelection(std::vector<sf::String>& options,
	const std::vector<int>& optionsSelectionsA, const std::vector<int>& optionsSelectionsB, const int settingsOptionA,
	const int settingsOptionB) const
{
	auto index = 0;
	for (auto selection : optionsSelectionsA)
	{
		if (selection == settingsOptionA && optionsSelectionsB.at(index) == settingsOptionB)
			return index;
		index++;
	}
	options.push_back(std::to_string(settingsOptionA) + "x" + std::to_string(settingsOptionB));
	return options.size() - 1;
}

void SettingsDataControllerImplementation::generateControlSettings() const
{
	const auto category1Name = Translations::getText(TextId::Apply);
	const auto category2Name = Translations::getText(TextId::Cancel);
	const auto category3Name = Translations::getText(TextId::RestoreDefaults);
	auto subCategories = std::vector<SubCategory*>();

	categories->push_back(generateSettingsCategory(category1Name, subCategories));
	categories->push_back(generateSettingsCategory(category2Name, subCategories));
	categories->push_back(generateSettingsCategory(category3Name, subCategories));
}

void SettingsDataControllerImplementation::generateSoundSettings(SettingsData& settingsData) const
{
	const auto categoryName = Translations::getText(TextId::Sound);
	auto subCategories = std::vector<SubCategory*>();

	const auto options1Name = Translations::getText(TextId::GameSound);
	auto options1 = std::vector<sf::String>{ Translations::getText(TextId::Off), Translations::getText(TextId::On) };
	const auto selection1 = checkBoolSelection(settingsConstance.boolSelection, settingsData.playSound);
	subCategories.push_back(generateSettingsSubCategory(options1Name, options1, selection1, SubCategoryIndicator::GameSound));

	const auto options2Name = Translations::getText(TextId::GameMusic);
	auto options2 = std::vector<sf::String>{ Translations::getText(TextId::Off), Translations::getText(TextId::On) };
	const auto selection2 = checkBoolSelection(settingsConstance.boolSelection, settingsData.playMusic);
	subCategories.push_back(generateSettingsSubCategory(options2Name, options2, selection2, SubCategoryIndicator::GameMusic));

	const auto option3Name = Translations::getText(TextId::GameSoundVolume);
	auto options3 = std::vector<sf::String>{ "0", "10", "20", "30", "40", "50", "60", "70", "80", "90", "100" };
	const auto selection3 = checkIntSelection(options3, settingsConstance.volumeSelection, settingsData.soundVolume);
	subCategories.push_back(generateSettingsSubCategory(option3Name, options3, selection3, SubCategoryIndicator::GameSoundVolume));

	const auto option4Name = Translations::getText(TextId::GameMusicVolume);
	auto options4 = std::vector<sf::String>{ "0", "10", "20", "30", "40", "50", "60", "70", "80", "90", "100" };
	const auto selection4 = checkIntSelection(options4, settingsConstance.volumeSelection, settingsData.musicVolume);
	subCategories.push_back(generateSettingsSubCategory(option4Name, options4, selection4, SubCategoryIndicator::GameMusicVolume));

	categories->push_back(generateSettingsCategory(categoryName, subCategories));
}

void SettingsDataControllerImplementation::generateVideoSettings(SettingsData& settingsData) const
{
	const auto categoryName = Translations::getText(TextId::Video);
	auto subCategories = std::vector<SubCategory*>();

	const auto options1Name = Translations::getText(TextId::Resolution);
	auto options1 = std::vector<sf::String>{ "800x600", "1024x768", "1280x900", "1440x900", "1600x900", "1920x1080", "1920x1200" };
	const auto selection1 = checkIntSelection(options1, settingsConstance.resolutionWidthSelection, settingsConstance.resolutionHeightSelection,
		settingsData.resolutionWidth, settingsData.resolutionHeight);
	subCategories.push_back(generateSettingsSubCategory(options1Name, options1, selection1, SubCategoryIndicator::Resolution));

	const auto options2Name = Translations::getText(TextId::FrameRateLimit);
	auto options2 = std::vector<sf::String>{ "30", "60", "120", "240", Translations::getText(TextId::Unlimited) };
	const auto selection2 = checkIntSelection(options2, settingsConstance.frameRateSelection, settingsData.frameRateLimit);
	subCategories.push_back(generateSettingsSubCategory(options2Name, options2, selection2, SubCategoryIndicator::FrameRateLimit));

	const auto options3Name = Translations::getText(TextId::VSyncEnabled);
	auto options3 = std::vector<sf::String>{ Translations::getText(TextId::No), Translations::getText(TextId::Yes) };
	const auto selection3 = checkBoolSelection(settingsConstance.boolSelection, settingsData.vSyncEnabled);
	subCategories.push_back(generateSettingsSubCategory(options3Name, options3, selection3, SubCategoryIndicator::VSyncEnabled));

	const auto options4Name = Translations::getText(TextId::Fullscreen);
	auto options4 = std::vector<sf::String>{ Translations::getText(TextId::Off), Translations::getText(TextId::On) };
	const auto selection4 = checkBoolSelection(settingsConstance.boolSelection, settingsData.fullscreen);
	subCategories.push_back(generateSettingsSubCategory(options4Name, options4, selection4, SubCategoryIndicator::Fullscreen));

	categories->push_back(generateSettingsCategory(categoryName, subCategories));
}

void SettingsDataControllerImplementation::generateOtherSettings(SettingsData& settingsData) const
{
	const auto categoryName = Translations::getText(TextId::Others);
	auto subCategories = std::vector<SubCategory*>();

	const auto options1Name = Translations::getText(TextId::Language);
	auto options1 = std::vector<sf::String>{ Translations::getText(TextId::English),
		Translations::getText(TextId::Polish), Translations::getText(TextId::Silesian) };
	const auto selection1 = checkIntSelection(options1, settingsConstance.languageSelection, settingsData.language);
	subCategories.push_back(generateSettingsSubCategory(options1Name, options1, selection1, SubCategoryIndicator::Language));

	categories->push_back(generateSettingsCategory(categoryName, subCategories));
}

SubCategory* SettingsDataControllerImplementation::generateSettingsSubCategory(const sf::String subCategoryName,
	std::vector<sf::String>& subCategoriesNames, const int currentSelection, const SubCategoryIndicator subCategoryIndicator) const
{
	auto subCategory = new SubCategory();
	subCategory->subCategoryName = createNewSettingsItem(subCategoryName);
	subCategory->subCategoriesOptionTexts = subCategoriesNames;
	subCategory->currentSelection = currentSelection;
	subCategory->subCategoryOption = createNewSettingsItem(subCategoriesNames.at(currentSelection));
	subCategory->subCategoryIndicator = subCategoryIndicator;
	return subCategory;
}

Category* SettingsDataControllerImplementation::generateSettingsCategory(const sf::String categoryName,
	std::vector<SubCategory*>& subCategories) const
{
	auto category = new Category();
	category->categoryName = createNewSettingsItem(categoryName);
	category->subCategories = subCategories;
	return category;
}

SettingsConstance& SettingsDataControllerImplementation::getSettingsConstance()
{
	return settingsConstance;
}

sf::Text* SettingsDataControllerImplementation::createNewSettingsItem(const sf::String text) const
{
	auto textView = new sf::Text();
	textView->setString(text);
	textView->setFont(font);
	textView->setFillColor(settingsConstance.normalColor);
	textView->setCharacterSize(ViewHelper::adjustFontSize(settingsConstance.selectTextSize, settingsView->getWindowSize()));
	return textView;
}

SettingsDataControllerImplementation::SettingsDataControllerImplementation(std::vector<Category*>* categories, SettingsView* settingsView)
{
	this->categories = categories;
	this->settingsView = settingsView;
}
