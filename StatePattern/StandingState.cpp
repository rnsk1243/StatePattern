#include "StandingState.h"
#include"JumpingState.h"

CStandingState::CStandingState()
{
}


CStandingState::~CStandingState()
{
}

CHeroineState* CStandingState::handleInput(CHeroine & heroine, int input)
{
	assert(this);
	/*
	if ()
	{
		//heroine.setGraphics(IMAGE_DUCK);
		//return new CDuckingState();
		// �����ְ� ��������쿡�� �� �� �ִ� �ൿ��...
	}
	else
	{
		//heroine.setGraphics(IMAGE_JUMP);
		return new CJumpingState();
		return COnGroundState::handleInput(heroine, input);
	}
	*/

	return COnGroundState::handleInput(heroine, input);


}

void CStandingState::update(CHeroine & heroine)
{
	//cout << "Idle ������..." << endl;
	// ���ִ� �̹���...
	heroine.setGraphics(IMAGE_STAND);
}

void CStandingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_STAND);
}
