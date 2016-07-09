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
		// ���������϶��� �� �� �ִ� Ư�� ���´� ���⿡
		//�Է�Ű�� �����ڸ��� ���¸� �ٲ� �� �ֵ��� ���� �ٲٱ⸦ ����Ѵ�.
		//�������̴� �ִϴ� ��� �����ǰ� ���� ���� �ִϰ� ����ȴ�.
		m_isChangeState = true;
		return new CDivingState();
	}
	else
	{
		// �Ʒ�Ű �̿��� �Է� Ű�δ� �ٷ� �ٸ� ���·� ��ȯ �� �� ����.
		// ������ ���� �ִϰ� �ٳ����� ���ִ� ���°� �Ǿ�� �Ѵ�.
		return COnSkyState::handleInput(heroine, input);
	}
	
	// ���� ���� �����̰� ���������϶��� �� �� �ִ� Ư�� ���´� ��������� �ʾ� if���� else���� ������ �´�.
	//m_isChangeState = true;
	//return COnSkyState::handleInput(heroine, input);
	
}

void CJumpingState::update(CHeroine & heroine)
{
	//cout << "���� ���� update" << m_aniTime << endl;
	heroine.setGraphics(IMAGE_JUMP);
	m_aniTime -= 0.25;
	if (m_aniTime < 0)
	{
		//cout << " ��ü ��.........................." << endl;
		// ������ȯ ����
		m_isChangeState = true;
	}
}

void CJumpingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_JUMP);
}


