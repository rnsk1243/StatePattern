#include "StateStack.h"



CStateStack::CStateStack():m_top(nullptr)
{
}


CStateStack::~CStateStack()
{
}

void CStateStack::push(CHeroineState * state)
{
	// 스택이 비어있을 경우에만 상태를 담을 수 있다.
	// 이유는 상태를 2가지 이상 담아버리면
	// 여러가지 상태를 담아 버릴 수도 있어서 
	// 현재 상태와 다음 상태만 담아둔다.
	if (state != nullptr && isEmpty())
	{
		nodeState* newNode = new nodeState();
		newNode->itemState = state;

		newNode->next = m_top;
		m_top = newNode;
		cout << state << "푸쉬 성공" << endl;
	}
}

CHeroineState * CStateStack::pop()
{
	if (isEmpty())
	{
		cout << "스택에서 nullptr 리턴함" << endl;
		return nullptr;
	}
	else {
		CHeroineState& temp = *m_top->itemState;
		nodeState* delNode = m_top;
		m_top = m_top->next;
		delete delNode;
		//cout << "스택에서 나온값 = " << &temp << endl;
		return &temp;
	}
}
