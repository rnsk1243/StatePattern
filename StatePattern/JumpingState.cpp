#include "JumpingState.h"



CJumpingState::CJumpingState()
{
}


CJumpingState::~CJumpingState()
{
}

void CJumpingState::handleInput(CHeroine & heroine, Input input)
{
	if (input == PRESS_DOWN)
	{
		heroine.setGraphics(IMAGE_DIVE);
	}
}

void CJumpingState::update(CHeroine & heroine)
{
	//cout << "점프 상태" << endl;
	heroine.setGraphics(IMAGE_JUMP);
}
