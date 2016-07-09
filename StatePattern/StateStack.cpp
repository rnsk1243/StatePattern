#include "StateStack.h"



CStateStack::CStateStack():m_top(nullptr)
{
}


CStateStack::~CStateStack()
{
}

void CStateStack::push(CHeroineState * state)
{
	// ������ ������� ��쿡�� ���¸� ���� �� �ִ�.
	// ������ ���¸� 2���� �̻� ��ƹ�����
	// �������� ���¸� ��� ���� ���� �־ 
	// ���� ���¿� ���� ���¸� ��Ƶд�.
	if (state != nullptr && isEmpty())
	{
		nodeState* newNode = new nodeState();
		newNode->itemState = state;

		newNode->next = m_top;
		m_top = newNode;
		cout << state << "Ǫ�� ����" << endl;
	}
}

CHeroineState * CStateStack::pop()
{
	if (isEmpty())
	{
		cout << "���ÿ��� nullptr ������" << endl;
		return nullptr;
	}
	else {
		CHeroineState& temp = *m_top->itemState;
		nodeState* delNode = m_top;
		m_top = m_top->next;
		delete delNode;
		//cout << "���ÿ��� ���°� = " << &temp << endl;
		return &temp;
	}
}
