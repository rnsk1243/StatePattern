#include "JumpingState.h"
#include"DivingState.h"

CJumpingState::CJumpingState():m_aniTime(1.5), m_isChangeState(false)
{
}


CJumpingState::~CJumpingState()
{
}

CHeroineState* CJumpingState::handleInput(CHeroine & heroine, int input)
{
	
	if (input == PRESS_DOWN)
	{
		//heroine.setGraphics(IMAGE_DIVE);
		//return new CDivingState();
		// 점프상태일때만 할 수 있는 특별 상태는 여기에
		//입력키를 누르자마자 상태를 바꿀 수 있도록 상태 바꾸기를 허락한다.
		//진행중이던 애니는 즉시 중지되고 다음 상태 애니가 실행된다.
		m_isChangeState = true;
		return new CDivingState();
	}
	else
	{
		// 아래키 이외의 입력 키로는 바로 다른 상태로 전환 할 수 없다.
		// 무조건 점프 애니가 다끝나고 서있는 상태가 되어야 한다.
		return COnSkyState::handleInput(heroine, input);
	}
	
	// 현재 공중 상태이고 점프상태일때만 할 수 있는 특별 상태는 만들어지지 않아 if문의 else문을 끄집어 냈다.
	//m_isChangeState = true;
	//return COnSkyState::handleInput(heroine, input);
	
}

void CJumpingState::update(CHeroine & heroine)
{
	//cout << "점프 상태 update" << m_aniTime << endl;
	heroine.setGraphics(IMAGE_JUMP);
	m_aniTime -= 0.25;
	if (m_aniTime < 0)
	{
		//cout << " 대체 왜.........................." << endl;
		// 상태전환 가능
		m_isChangeState = true;
	}
}

void CJumpingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_JUMP);
}


