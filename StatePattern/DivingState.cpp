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
		// ���߻����̰� ������� �����϶� ��ȯ ������ ���¸� �����ϴ� �� �Դϴ�.

		// ���ִ� ����
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
