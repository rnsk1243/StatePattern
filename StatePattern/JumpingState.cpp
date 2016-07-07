#include "JumpingState.h"


CJumpingState::CJumpingState()
{
}


CJumpingState::~CJumpingState()
{
}

CHeroineState* CJumpingState::handleInput(CHeroine & heroine, int input)
{
	/*
	if (input == 특별공격키)
	{
		//heroine.setGraphics(IMAGE_DIVE);
		//return new CDivingState();
		// 공중 상태이고 점프상태일때만 할 수 있는 특별 상태는 여기에
	}
	else
	{
		return COnSkyState::handleInput(heroine, input);
	}
	*/
	cout << "점프상태!!!!!!!!!!." << endl;
	return COnSkyState::handleInput(heroine, input);
	
}

void CJumpingState::update(CHeroine & heroine)
{
	//cout << "점프 상태" << endl;
	heroine.setGraphics(IMAGE_JUMP);
}

void CJumpingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_JUMP);
}


