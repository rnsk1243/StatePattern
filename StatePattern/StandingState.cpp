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
		// 땅에있고 서있을경우에만 할 수 있는 행동들...
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
	//cout << "Idle 동작중..." << endl;
	// 서있는 이미지...
	heroine.setGraphics(IMAGE_STAND);
}

void CStandingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_STAND);
}
