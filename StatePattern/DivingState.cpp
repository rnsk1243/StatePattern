#include "DivingState.h"



CDivingState::CDivingState()
{
}


CDivingState::~CDivingState()
{
}

void CDivingState::handleInput(CHeroine & heroine, Input input)
{
	if (input == RELEASE_DOWN)
	{
		heroine.setGraphics(IMAGE_STAND);
	}
}

void CDivingState::update(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_DIVE);
}
