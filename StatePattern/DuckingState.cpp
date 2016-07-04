#include "DuckingState.h"

enum Time
{
	MAX_CHARGE = 20
};

CDuckingState::CDuckingState() :m_chargeTime(0) {}


CDuckingState::~CDuckingState() {}

void CDuckingState::handleInput(CHeroine & heroine, Input input)
{
	// ���帮�� ���� �̸�
	if (input == RELEASE_DOWN)
	{
		// ���ִ� �̹���
		heroine.setGraphics(IMAGE_STAND);
		// ���ְ� �Ǹ� ����Ÿ�� �ʱ�ȭ
		m_chargeTime = 0;
	}
}

void CDuckingState::update(CHeroine & heroine)
{
	m_chargeTime++;
	if (m_chargeTime > MAX_CHARGE) {
		heroine.superBomb();
		m_chargeTime = 0;
	}
}
