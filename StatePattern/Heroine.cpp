#include "Heroine.h"
#include<conio.h>
#include"StandingState.h"
#include<assert.h>

CHeroine::CHeroine():m_state(new CStandingState())
{
	assert(m_state);
}


CHeroine::~CHeroine()
{
}

Input CHeroine::command()
{
	char ch;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
				//b
			case 98:
				return PRESS_B;
			case 80:
				return PRESS_DOWN;
			case 72:
				return RELEASE_DOWN;
			}
			if (ch == 'q')
				break;
		}
	}
	return PRESS_NIL;
}

void CHeroine::setGraphics(int command)
{
	switch (command)
	{
	case IMAGE_DUCK:
		cout << "���帮�� �̹��� ����" << endl;
		break;
	case IMAGE_DIVE:
		cout << "������� �̹��� ����" << endl;
		break;
	case IMAGE_STAND:
		cout << "���ִ� �̹��� ����" << endl;
		break;
	case IMAGE_JUMP:
		cout << "�����ϴ� �̹��� ����" << endl;
		break;
	default:
		break;
	}
}

void CHeroine::superBomb()
{
	cout << "���ۺ� �߻�!!!" << endl;
}

CHeroineState* CHeroine::handleInput(Input input)
{
	// ���°�ü �ּҸ� ��� state������ �����ϰ�
	// m_state(���� ���°�ü�� ����Ű�� �ּ�)�� handleInput �޼ҵ带 ȣ���ϴµ� �Ķ���ͷ�
	// *this�� CHeroine�ڽ� ��ü�� ����ڰ� �Է��ϴ� ���� ���� �˸��� ���� ��ü �ּҸ� ��ȯ�Ѵ�.
	// m_state�� ���� ����Ű�� �ִ� ���� ��ü�� handleInput�޼ҵ带 ȣ���Ѵ�.
	// ��� ���� ��ü�� CHeroineState�� ��ӹ޾ұ⶧���� CHeroineState ������ ������ �ʱ�ȭ �� �� �ִ�.
	CHeroineState* state = m_state->handleInput(*this, input);
	// ���� ���°� �����ϸ�(���ο� �Է¿����� �ʱ�ȭ �Ǹ�)
	if (state != NULL)
	{
		// ���� ���¸� ����������(���¸� �ٲپ���ϴϱ�)
		delete m_state;
		// ��� �ʱ�ȭ�� ���������� ������·� �ʱ�ȭ ���ش�.
		m_state = state;
	}
	// ���������� ������¸� ��ȯ��.
	return m_state;
}
