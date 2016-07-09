#include "Heroine.h"
#include<conio.h>
#include"StandingState.h"
#include<assert.h>

// ���� ���� �������� ó�� ���¸� �ʱ�ȭ ���ش�.
// ���������� �ܺο��� �ʱ�ȭ ���־����. �����ں��� ���� ȣ�� �ǹǷ�
// �׸��� .cpp���� �ʱ�ȭ ���־��µ� ������ CStandingState()��ü�� .h���� ����� �� ��� (�ڽ� ��ü ����� �θ������ ��Ŭ����ϸ� ���� ����� �ϱ�..
CHeroineState* CHeroine::m_standingState = new CStandingState();
CHeroineState* CHeroine::m_state = CHeroine::m_standingState;

CHeroine::CHeroine(): m_stack(new CStateStack())
{
	assert(m_state);
	//m_stack->push(new CStandingState());
	
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

void CHeroine::handleInput(Input input)
{
	// ���°�ü �ּҸ� ��� state������ �����ϰ�
	// m_state(���� ���°�ü�� ����Ű�� �ּ�)�� handleInput �޼ҵ带 ȣ���ϴµ� �Ķ���ͷ�
	// *this�� CHeroine�ڽ� ��ü�� ����ڰ� �Է��ϴ� ���� ���� �˸��� ���� ��ü �ּҸ� ��ȯ�Ѵ�.
	// m_state�� ���� ����Ű�� �ִ� ���� ��ü�� handleInput�޼ҵ带 ȣ���Ѵ�.
	// ��� ���� ��ü�� CHeroineState�� ��ӹ޾ұ⶧���� CHeroineState ������ ������ �ʱ�ȭ �� �� �ִ�.
	CHeroineState* state = m_state->handleInput(*this, input);

	// ���¸� ���ÿ� ���
	m_stack->push(state);

	// ���� �Ǵٸ� ���±�谡 �ִٸ� ���⿡ �Է��� �����Ѵ�.
	// ��) CHeroineState* state2 = m_�Ǵٸ����±��->handleInput(*this, input);

	///////////////////////////// �Է��� ���������� ��� ���¸� �ٱ����� �Ҷ� ���� �ڵ� ///////////////////////////
	/*
	// ���� ���°� �����ϸ�(���ο� �Է¿����� �ʱ�ȭ �Ǹ�)
	if (state != NULL)
	{
		// ���� ���¸� ����������(���¸� �ٲپ���ϴϱ�)
		delete m_state;
		// ��� �ʱ�ȭ�� ���������� ������·� �ʱ�ȭ ���ش�.
		m_state = state;
		// ������ ���� ���� Ŭ�������� ���� ���� �̹����� ���� 
		// �̷��� ���ָ� ���� ���¿��� ������ ���� ���·� �Ѿ�� �̹����� ���� ���� �ʿ䰡 ����.
		// ��) DuckingState.cpp���� handleInput�޼ҵ忡�� ���¸� �ٲٴµ� �̶� ���ִ� �̹����� ���¸� �ٲ��� �ʿ䰡 ��������.
		// ���� ���¸� �����ϸ� �� ���°� �׷��� �̹������� �ڵ����� ì���ش�.
		m_state->enter(*this);
	}
	*/
	// ���������� ������¸� ��ȯ��.
	//return m_state;
}

void CHeroine::autoStateChange()
{
	// ���¸� �ٲ� �غ� �Ǿ��°�? ( �Ǵٸ� �Է��� ���԰ų� �ִϰ� ���� �Ǿ����� )
	// virtual�� ���� � ���°�ü�� new ��ü �ʱ�ȭ �ߴ��Ŀ����� �˸��� �޼ҵ尡 ȣ��ȴ�.
	// ��) ������°� �������̴ٶ�� ������ü�� getIsChangeState()�޼ҵ尡 ȣ���.
	if (m_state->getIsChangeState())
	{
		// ���� ������ ���������(idle����)
		if (m_stack->getTop() == nullptr)
		{
			cout << "������ ����ֽ��ϴ�." << endl;
			//delete m_state;
			// ���� ��ü ��� �ϱ�.
			m_state = CHeroine::m_standingState;
			m_state->enter(*this);
		}
		else {
			//cout << m_stack->getTop()->getIsChangeState() << endl;

			//cout << "���� ��ü �ϰڽ��ϴ�." << endl;
			//delete m_state;
			// ���ÿ� ��Ƶ� ���� ���� ��ü�ּҷ� �ٲ۴�.
			m_state = m_stack->pop();
			//cout << "m_state�� �ּ� : " << m_state << endl;
			// ���� ������ �����Ҷ� �ѹ� ����Ǵ� �޼ҵ�.
			m_state->enter(*this);

		}
	}

}
