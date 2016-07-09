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
		// �����ְ� ��������쿡�� �� �� �ִ� �ൿ��...
	}
	else
	{
		//heroine.setGraphics(IMAGE_JUMP);
		return new CJumpingState();
		return COnGroundState::handleInput(heroine, input);
	}
	*/
	// ���ִ� ���¶�� �ٷ� ���� ���·� �� �� �ִ�.
	m_isChangeState = true;
	return COnGroundState::handleInput(heroine, input);


}

void CStandingState::update(CHeroine & heroine)
{
	//cout << "Idle ������..." << endl;
	// ���ִ� �̹���...
	heroine.setGraphics(IMAGE_STAND);
	m_isChangeState = true;
}

void CStandingState::enter(CHeroine & heroine)
{
	//cout << "���ĵ� enter ȣ��" << endl;
	heroine.setGraphics(IMAGE_STAND);
}
