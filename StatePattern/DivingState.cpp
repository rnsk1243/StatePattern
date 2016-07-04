#include "DivingState.h"



CDivingState::CDivingState()
{
}


CDivingState::~CDivingState()
{
}

CHeroineState* CDivingState::handleInput(CHeroine & heroine, int input)
{
	if (input == RELEASE_DOWN)
	{
		heroine.setGraphics(IMAGE_STAND);
		return new CStandingState();
	}
	return nullptr;
}

void CDivingState::update(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_DIVE);
}
