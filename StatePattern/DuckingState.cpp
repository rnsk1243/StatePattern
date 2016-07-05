#include "DuckingState.h"

enum Time
{
	// �������� 3�̸� Ư���� ����� ��� �� �� �ִ�.
	MAX_CHARGE = 3
};

CDuckingState::CDuckingState() :m_chargeTime(0) {}


CDuckingState::~CDuckingState() {}

CHeroineState* CDuckingState::handleInput(CHeroine & heroine, int input)
{
	// ���帮�� ���� �̸�
	if (input == RELEASE_DOWN)
	{
		// ���ִ� �̹����� ���¸� �ٲ۴�.
		//heroine.setGraphics(IMAGE_STAND);
		// ���ְ� �Ǹ� ����Ÿ�� �ʱ�ȭ
		m_chargeTime = 0;
		// ���帮�� ���� ��ɿ����ؼ� ���ִ� ����  ��ü�� ����� �� �ּҸ� ������.
		return new CStandingState();
	}
	// ���帮�� ���� ��� �̿��� ����� �� nullptr�� �����Ͽ� ���¸� �ٲ��� �ʰ� ������.
	return nullptr;
	//return NULL;  �̷��� �ص� �ȴ�.
}

void CDuckingState::update(CHeroine & heroine)
{
	// ���帰���¿����� �������� �����Ѵ�.
	m_chargeTime++;
	if (m_chargeTime > MAX_CHARGE) {
		// Ư����� �ߵ�!
		heroine.superBomb();
		// �ߵ��� �ٽ� 0����.
		m_chargeTime = 0;
	}
}

void CDuckingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_DUCK);
}
