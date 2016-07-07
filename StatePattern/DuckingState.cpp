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
		cout << "DuckingState : ���帮�� ����" << endl;
		return new CStandingState();
	}
	else {
		return CUnderGround::handleInput(heroine, input);
	}
	// ���帮�� ���� ��� �̿��� ����� �� nullptr�� �����Ͽ� ���¸� �ٲ��� �ʰ� ������.
	//return nullptr;
	//return NULL;  �̷��� �ص� �ȴ�.
}

void CDuckingState::update(CHeroine & heroine)
{
	// ���帰���¿����� �������� �����Ѵ�.
	cout << "�ñر� ������... : " << m_chargeTime << endl;
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
	cout << "�ñر⸦ ���� �մϴ�." << endl;
	heroine.setGraphics(IMAGE_DUCK);
}
