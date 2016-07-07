#include "DivingState.h"



CDivingState::CDivingState()
{
}


CDivingState::~CDivingState()
{
}

CHeroineState* CDivingState::handleInput(CHeroine & heroine, int input)
{
	/*
	if (input == RELEASE_DOWN)
	{
		//heroine.setGraphics(IMAGE_STAND);
		//return new CStandingState();
		// 공중상태이고 내려찍기 상태일때 전환 가능한 상태를 리턴하는 곳 입니다.

		// 서있는 상태
		return new CStandingState();
		//////////////////////////////////////////////////////////////////////////
	}else{
		return COnSkyState::handleInput(heroine, input);
	}
	*/

	return CMiddle::handleInput(heroine, input);
	
}

void CDivingState::update(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_DIVE);
}

void CDivingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_DIVE);
}
