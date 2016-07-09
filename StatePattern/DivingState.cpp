#include "DivingState.h"



CDivingState::CDivingState():m_aniTime(1.0), m_isChangeState(false)
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
	//->(x)m_isChangeState = true; 드라이버 상태에서는 다음 행동으로 바로 갈 수 없도록(애니가 끝나야함) true값을 주지 않는다.
	return CMiddle::handleInput(heroine, input);
	
}

void CDivingState::update(CHeroine & heroine)
{
	m_aniTime -= 1;
	if (m_aniTime < 0)
	{
		// 애니 시간이 다 되면 
		m_isChangeState = true;
	}else{
		// 아직 애니 재생시간이 남으면
		// 내려찍기 이미지를 계속 보여주며
		heroine.setGraphics(IMAGE_DIVE);
		// 다음 상태로 아직 못가도록 false준다.
		m_isChangeState = false;
	}
}

void CDivingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_DIVE);
}
