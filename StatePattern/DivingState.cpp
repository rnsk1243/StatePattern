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
		// ���߻����̰� ������� �����϶� ��ȯ ������ ���¸� �����ϴ� �� �Դϴ�.

		// ���ִ� ����
		return new CStandingState();
		//////////////////////////////////////////////////////////////////////////
	}else{
		return COnSkyState::handleInput(heroine, input);
	}
	*/
	//->(x)m_isChangeState = true; ����̹� ���¿����� ���� �ൿ���� �ٷ� �� �� ������(�ִϰ� ��������) true���� ���� �ʴ´�.
	return CMiddle::handleInput(heroine, input);
	
}

void CDivingState::update(CHeroine & heroine)
{
	m_aniTime -= 1;
	if (m_aniTime < 0)
	{
		// �ִ� �ð��� �� �Ǹ� 
		m_isChangeState = true;
	}else{
		// ���� �ִ� ����ð��� ������
		// ������� �̹����� ��� �����ָ�
		heroine.setGraphics(IMAGE_DIVE);
		// ���� ���·� ���� �������� false�ش�.
		m_isChangeState = false;
	}
}

void CDivingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_DIVE);
}
