#include "StandingState.h"
#include"JumpingState.h"

CStandingState::CStandingState():m_isChangeState(true)
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
	// 서있는 상태라면 바로 다음 상태로 갈 수 있다.
	m_isChangeState = true;
	return COnGroundState::handleInput(heroine, input);


}

void CStandingState::update(CHeroine & heroine)
{
	//cout << "Idle 동작중..." << endl;
	// 서있는 이미지...
	heroine.setGraphics(IMAGE_STAND);
	m_isChangeState = true;
}

void CStandingState::enter(CHeroine & heroine)
{
	//cout << "스탠딩 enter 호출" << endl;
	heroine.setGraphics(IMAGE_STAND);
}
