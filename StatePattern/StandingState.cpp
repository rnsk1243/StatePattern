#include "StandingState.h"



CStandingState::CStandingState()
{
}


CStandingState::~CStandingState()
{
}

void CStandingState::handleInput(CHeroine & heroine, Input input)
{
	if (input == PRESS_DOWN)
	{
		heroine.setGraphics(IMAGE_DUCK);
	}
	else if (input == PRESS_B)
	{
		heroine.setGraphics(IMAGE_JUMP);
	}
}

void CStandingState::update(CHeroine & heroine)
{
	//cout << "Idle µ¿ÀÛÁß..." << endl;
	heroine.setGraphics(IMAGE_STAND);
}
