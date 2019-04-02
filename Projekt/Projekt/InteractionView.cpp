#include "stdafx.h"
#include "InteractionView.h"
#include "Log.h"


void InteractionView::show()
{
	Log::debugA("now will be displaying interaction");
}

InteractionView::InteractionView(sf::RenderWindow* window, Interactive* doneInteraction) : window(window), doneInteraction(doneInteraction)
{
}

InteractionView::~InteractionView()
{
}
