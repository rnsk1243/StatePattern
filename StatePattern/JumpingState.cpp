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
	if (input == Ư������Ű)
	{
		//heroine.setGraphics(IMAGE_DIVE);
		//return new CDivingState();
		// ���� �����̰� ���������϶��� �� �� �ִ� Ư�� ���´� ���⿡
	}
	else
	{
		return COnSkyState::handleInput(heroine, input);
	}
	*/
	cout << "��������!!!!!!!!!!." << endl;
	return COnSkyState::handleInput(heroine, input);
	
}

void CJumpingState::update(CHeroine & heroine)
{
	//cout << "���� ����" << endl;
	heroine.setGraphics(IMAGE_JUMP);
}

void CJumpingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_JUMP);
}


