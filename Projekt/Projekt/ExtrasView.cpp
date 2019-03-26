#include "stdafx.h"
#include "ExtrasView.h"
#include "FileNameHelper.h"
#include "ViewHelper.h"
#include "TexturesHolder.h"
#include "InterfaceTexturesHolder.h"

sf::Text* ExtrasView::createNewItem(const sf::String& text) const
{
	auto textView = new sf::Text();
	textView->setString(text);
	textView->setFont(font);
	textView->setFillColor(color);
	textView->setCharacterSize(ViewHelper::adjustFontSize(textSize, window->getSize()));
	return textView;
}

void ExtrasView::repositionItems(const sf::Time& elapsedTime)
{
	if (speed < 0)
		speed = 0;
	for (auto text : *texts)
		text->move(0, -speed * elapsedTime.asSeconds());
	const auto lastItem = texts->back();
	if (lastItem->getPosition().y + lastItem->getGlobalBounds().height < 0)
		shouldShowWindow = false;
}

void ExtrasView::setInitialPosition(const sf::Vector2u& windowSize) const
{
	auto nextPosition = static_cast<float>(windowSize.y);
	for (auto text : *texts)
	{
		const auto x = (windowSize.x - text->getGlobalBounds().width) / 2;
		const auto y = nextPosition;
		nextPosition += text->getGlobalBounds().height * 2.0f;
		text->setPosition(x, y);
	}
}

void ExtrasView::show()
{
	shouldShowWindow = true;
	auto& window = *this->window;
	sf::Clock gameClock;
	while (window.isOpen() && shouldShowWindow)
	{
		auto elapsed = gameClock.restart();
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Escape)
					shouldShowWindow = false;
				else if (e.key.code == sf::Keyboard::W)
					speed += 30.0f;
				else if (e.key.code == sf::Keyboard::S)
					speed -= 30.0f;
			}
		}
		repositionItems(elapsed);
		window.clear();
		window.draw(*background);
		for (auto text : *texts)
			window.draw(*text);
		window.display();
	}
}

ExtrasView::ExtrasView(sf::RenderWindow* window)
{
	this->window = window;
	texts = new std::vector<sf::Text*>();

	const auto windowSize = window->getSize();

	font.loadFromFile(FileNameHelper::getFontFileName(FontIndicator::Arial));
	texts->push_back(createNewItem(Translations::getText(TextId::StartNewGame)));
	texts->push_back(createNewItem(Translations::getText(TextId::LoadGame)));
	texts->push_back(createNewItem(Translations::getText(TextId::Settings)));
	texts->push_back(createNewItem(Translations::getText(TextId::Extras)));
	texts->push_back(createNewItem(Translations::getText(TextId::Quit)));

	auto& texture = InterfaceTexturesHolder::getInstance()->getTexture(InterfaceTextureIndicator::MenuBackground);
	texture.setRepeated(true);
	const auto rects = sf::IntRect(0, 0, windowSize.x, windowSize.y);
	background = new sf::Sprite(texture, rects);

	setInitialPosition(windowSize);
}

ExtrasView::~ExtrasView()
{
	delete background;
	for (auto text : *texts)
		delete text;
	delete texts;
}
