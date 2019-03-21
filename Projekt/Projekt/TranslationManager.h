#pragma once
class TranslationManager
{
public:
	virtual void reloadTranslations() = 0;
	virtual ~TranslationManager() = default;
};

