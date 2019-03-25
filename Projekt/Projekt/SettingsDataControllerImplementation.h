#pragma once
#include <SFML/Graphics/Text.hpp>
#include "SettingsControllerImplementation.h"

class SettingsDataControllerImplementation : public SettingsDataController
{

	sf::Font font;

	SettingsView* settingsView;
	std::vector<Category*>* categories;

	static int checkBoolSelection(const std::vector<bool>& optionsSelections, bool settingsOption);
	int checkIntSelection(std::vector<sf::String>& options, const std::vector<int>& optionsSelections, int settingsOption) const;
	int checkIntSelection(std::vector<sf::String>& options, const std::vector<int>& optionsSelectionsA,
		const std::vector<int>& optionsSelectionsB, int settingsOptionA, int settingsOptionB) const;
	void generateControlSettings() const;
	void generateSoundSettings(const SettingsData& settingsData) const;
	void generateVideoSettings(const SettingsData& settingsData) const;
	void generateOtherSettings(const SettingsData& settingsData) const;
	SubCategory* generateSettingsSubCategory(
		const sf::String& subCategoryName,
		std::vector<sf::String>& subCategoriesNames,
		int currentSelection, 
		SubCategoryIndicator subCategoryIndicator) const;
	Category* generateSettingsCategory(const sf::String& categoryName, std::vector<SubCategory*>& subCategories) const;
	

public:
	SettingsConstance& getSettingsConstance() override;
	sf::Text* createNewSettingsItem(const sf::String& text) const override;
	void initialize(SettingsData& settingsData) override;
	explicit SettingsDataControllerImplementation(std::vector<Category*>* categories, SettingsView* settingsView);
};

