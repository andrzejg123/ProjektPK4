#include "stdafx.h"
#include "Interactive.h"

Interactive::Interactive(InteractionType interactionType, AnimationData& animationData) : interactionType(interactionType), Animated(animationData)
{
}

Interactive::~Interactive()
{
}
