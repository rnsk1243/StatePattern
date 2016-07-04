#include "JumpingState.h"



CJumpingState::CJumpingState()
{
}


CJumpingState::~CJumpingState()
{
}

CHeroineState* CJumpingState::handleInput(CHeroine & heroine, int input)
{
	if (input == PRESS_DOWN)
	{
		heroine.setGraphics(IMAGE_DIVE);
		return new CDivingState();
	}
	return nullptr;
}

void CJumpingState::update(CHeroine & heroine)
{
	//cout << "���� ����" << endl;
	heroine.setGraphics(IMAGE_JUMP);
}
