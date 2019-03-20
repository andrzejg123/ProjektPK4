#include "stdafx.h"
#include "SettingsGeneratorImplementation.h"
#include <iostream>

void SettingsGeneratorImplementation::initialize(const SettingsData settingsData)
{
	if (font.loadFromFile("fonts/font_0.ttf"))
	{
		generateVideoSettings(settingsData);
		generateSoundSettings(settingsData);
		generateApplyCancelSettings();
	}
}

int SettingsGeneratorImplementation::checkBoolSelection(const std::vector<bool>& optionsSelections, const bool settingsOption)
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

int SettingsGeneratorImplementation::checkIntSelection(std::vector<const char*>& options, const std::vector<int>& optionsSelections,
                                                       const int settingsOption) const
{
	auto index = 0;
	for (auto selection : optionsSelections)
	{
		if (selection == settingsOption)
			return index;
		index++;
	}
	additionalStrings->push_front(std::to_string(settingsOption));
	options.push_back(additionalStrings->front().c_str());
	return options.size() - 1;
}

int SettingsGeneratorImplementation::checkIntSelection(std::vector<const char*>& options,
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
	additionalStrings->push_front(std::to_string(settingsOptionA) + "x" + std::to_string(settingsOptionB));
	options.push_back(additionalStrings->front().c_str());
	return options.size() - 1;
}

void SettingsGeneratorImplementation::generateApplyCancelSettings() const
{
	const auto category1Name = "Apply";
	const auto category2Name = "Cancel";
	const auto category3Name = "Restore defaults";
	auto subCategories = std::vector<SubCategory*>();

	categories->push_back(generateSettingsCategory(category1Name, subCategories));
	categories->push_back(generateSettingsCategory(category2Name, subCategories));
	categories->push_back(generateSettingsCategory(category3Name, subCategories));
}

void SettingsGeneratorImplementation::generateSoundSettings(const SettingsData settingsData) const
{
	const auto categoryName = "Sound";
	auto subCategories = std::vector<SubCategory*>();

	const auto options1Name = "Game sound";
	auto options1 = std::vector<const char*>{ "Off", "On" };
	const auto selection1 = checkBoolSelection(boolSelection, settingsData.playSound);
	subCategories.push_back(generateSettingsSubCategory(options1Name, options1, selection1, SubCategoryIndicator::GameSound));

	const auto options2Name = "Game music";
	auto options2 = std::vector<const char*>{ "Off", "On" };
	const auto selection2 = checkBoolSelection(boolSelection, settingsData.playMusic);
	subCategories.push_back(generateSettingsSubCategory(options2Name, options2, selection2, SubCategoryIndicator::GameMusic));

	const auto option3Name = "Game sound volume";
	auto options3 = std::vector<const char*>{ "0", "10", "20", "30", "40", "50", "60", "70", "80", "90", "100" };
	const auto selection3 = checkIntSelection(options3, volumeSelection, settingsData.soundVolume);
	subCategories.push_back(generateSettingsSubCategory(option3Name, options3, selection3, SubCategoryIndicator::GameSoundVolume));

	const auto option4Name = "Game music volume";
	auto options4 = std::vector<const char*>{ "0", "10", "20", "30", "40", "50", "60", "70", "80", "90", "100" };
	const auto selection4 = checkIntSelection(options4, volumeSelection, settingsData.musicVolume);
	subCategories.push_back(generateSettingsSubCategory(option4Name, options4, selection4, SubCategoryIndicator::GameMusicVolume));

	categories->push_back(generateSettingsCategory(categoryName, subCategories));
}

void SettingsGeneratorImplementation::generateVideoSettings(const SettingsData settingsData) const
{
	const auto categoryName = "Video";
	auto subCategories = std::vector<SubCategory*>();

	const auto options1Name = "Resolution";
	auto options1 = std::vector<const char*>{ "800x600", "1024x768", "1280x900", "1440x900", "1600x900", "1920x1080", "1920x1200" };
	const auto selection1 = checkIntSelection(options1, resolutionWidthSelection, resolutionHeightSelection,
		settingsData.resolutionWidth, settingsData.resolutionHeight);
	subCategories.push_back(generateSettingsSubCategory(options1Name, options1, selection1, SubCategoryIndicator::Resolution));

	const auto options2Name = "Frame rate limit";
	auto options2 = std::vector<const char*>{ "30", "60", "120", "240", "Unlimited" };
	const auto selection2 = checkIntSelection(options2, frameRateSelection, settingsData.frameRateLimit);
	subCategories.push_back(generateSettingsSubCategory(options2Name, options2, selection2, SubCategoryIndicator::FrameRateLimit));

	const auto options3Name = "VSync enabled";
	auto options3 = std::vector<const char*>{ "No", "Yes" };
	const auto selection3 = checkBoolSelection(boolSelection, settingsData.vSyncEnabled);
	subCategories.push_back(generateSettingsSubCategory(options3Name, options3, selection3, SubCategoryIndicator::VSyncEnabled));

	const auto options4Name = "Fullscreen";
	auto options4 = std::vector<const char*>{ "Off", "On" };
	const auto selection4 = checkBoolSelection(boolSelection, settingsData.fullscreen);
	subCategories.push_back(generateSettingsSubCategory(options4Name, options4, selection4, SubCategoryIndicator::Fullscreen));

	categories->push_back(generateSettingsCategory(categoryName, subCategories));
}

SubCategory* SettingsGeneratorImplementation::generateSettingsSubCategory(const char* subCategoryName,
	std::vector<const char*>& subCategoriesNames, const int currentSelection, const SubCategoryIndicator subCategoryIndicator) const
{
	auto subCategory = new SubCategory();
	subCategory->subCategoryName = createNewSettingsItem(subCategoryName);
	subCategory->subCategoriesOptionTexts = subCategoriesNames;
	subCategory->currentSelection = currentSelection;
	subCategory->subCategoryOption = createNewSettingsItem(subCategoriesNames.at(currentSelection));
	subCategory->subCategoryIndicator = subCategoryIndicator;
	return subCategory;
}

Category* SettingsGeneratorImplementation::generateSettingsCategory(const char* categoryName,
	std::vector<SubCategory*>& subCategories) const
{
	auto category = new Category();
	category->categoryName = createNewSettingsItem(categoryName);
	category->subCategories = subCategories;
	return category;
}

sf::Text* SettingsGeneratorImplementation::createNewSettingsItem(const char* text) const
{
	auto textView = new sf::Text();
	textView->setString(text);
	textView->setFont(font);
	textView->setFillColor(normalColor);
	textView->setCharacterSize(normalTextSize);
	return textView;
}

SettingsGeneratorImplementation::SettingsGeneratorImplementation(std::vector<Category*>* categories)
{
	this->additionalStrings = new std::list<std::string>();
	this->categories = categories;
}

SettingsGeneratorImplementation::~SettingsGeneratorImplementation()
{
	delete additionalStrings;
}
