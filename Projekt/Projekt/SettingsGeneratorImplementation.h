#pragma once
#include <SFML/Graphics/Text.hpp>
#include "SettingsControllerImplementation.h"

class SettingsGeneratorImplementation : public SettingsGenerator
{

	sf::Font font;

	std::list<std::string>* additionalStrings;
	std::vector<Category*>* categories;

	static int checkBoolSelection(const std::vector<bool>& optionsSelections, bool settingsOption);
	int checkIntSelection(std::vector<const char*>& options, const std::vector<int>& optionsSelections, int settingsOption) const;
	int checkIntSelection(std::vector<const char*>& options, const std::vector<int>& optionsSelectionsA,
		const std::vector<int>& optionsSelectionsB, int settingsOptionA, int settingsOptionB) const;
	void generateApplyCancelSettings() const;
	void generateSoundSettings(SettingsData settingsData) const;
	void generateVideoSettings(SettingsData settingsData) const;
	SubCategory* generateSettingsSubCategory(
		const char* subCategoryName,
		std::vector<const char*>& subCategoriesNames,
		int currentSelection, 
		SubCategoryIndicator subCategoryIndicator) const;
	Category* generateSettingsCategory(const char* categoryName, std::vector<SubCategory*>& subCategories) const;
	

public:
	sf::Text* createNewSettingsItem(const char* text) const override;
	void initialize(SettingsData settingsData) override;
	explicit SettingsGeneratorImplementation(std::vector<Category*>* categories);
	~SettingsGeneratorImplementation();
};

