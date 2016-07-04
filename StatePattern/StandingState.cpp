#include "StandingState.h"


CStandingState::CStandingState()
{
}


CStandingState::~CStandingState()
{
}

CHeroineState* CStandingState::handleInput(CHeroine & heroine, int input)
{
	assert(this);
	if (input == PRESS_DOWN)
	{
		heroine.setGraphics(IMAGE_DUCK);
		return new CDuckingState();
	}
	else if (input == PRESS_B)
	{
		heroine.setGraphics(IMAGE_JUMP);
		return new CJumpingState();
	}

	return nullptr;
}

void CStandingState::update(CHeroine & heroine)
{
	//cout << "Idle ������..." << endl;
	// ���ִ� �̹���...
	heroine.setGraphics(IMAGE_STAND);
}
