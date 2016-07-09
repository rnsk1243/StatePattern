#include "DuckingState.h"

enum Time
{
	// �������� 3�̸� Ư���� ����� ��� �� �� �ִ�.
	MAX_CHARGE = 30
};

CDuckingState::CDuckingState() :m_chargeTime(0), m_isChangeState(false) {}


CDuckingState::~CDuckingState() {}

CHeroineState* CDuckingState::handleInput(CHeroine & heroine, int input)
{
	// �����̰� ���帰 �����϶��� ��ȯ ������ ����
	// ���帮�� ���� �̸�
	if (input == RELEASE_DOWN)
	{
		// ���ִ� �̹����� ���¸� �ٲ۴�.
		//heroine.setGraphics(IMAGE_STAND);
		// ���ְ� �Ǹ� ����Ÿ�� �ʱ�ȭ
		m_chargeTime = 0;
		// ���帮�� ���� ��ɿ����ؼ� ���ִ� ����  ��ü�� ����� �� �ּҸ� ������.
		cout << "DuckingState : ���帮�� ����" << endl;
		// ���� �׸��ϰ� ���� ���ô�
		m_isChangeState = true;
		// ������ ��� ������ autoStateChange()�޼ҵ忡�� �ڵ����� ���ִ� ���·� ��ȯ �ϹǷ� nullptr�� �����մϴ�.
		return nullptr; // new CStandingState(); //<< ���� �̷��� �ص� ������ cpu�����ϸ� ��ü�� ���� ���� �� �ʿ�� ����.
		//return CHeroine::m_standingState; <<- �̷��� ���� ��ü�� �����ص� �ȴ�.
	}
	else {
		//m_isChangeState = true;
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
		// ���� ���·� ���ư��� ���º�ȭ ���� pop �ص� ���ƿ�.
		m_isChangeState = true;
	}

}

void CDuckingState::enter(CHeroine & heroine)
{
	cout << "�ñر⸦ ���� �մϴ�." << endl;
	heroine.setGraphics(IMAGE_DUCK);
}
