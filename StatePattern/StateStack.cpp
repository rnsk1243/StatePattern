#include "StateStack.h"



CStateStack::CStateStack():m_top(nullptr)
{
}


CStateStack::~CStateStack()
{
}

void CStateStack::push(CHeroineState * state)
{
	nodeState* newNode = new nodeState();
	newNode->itemState = state;

	newNode->next = m_top;
	m_top = newNode;

}

CHeroineState * CStateStack::pop()
{
	if (isEmpty())
	{
		return nullptr;
	}
	else {
		CHeroineState& temp = *m_top->itemState;
		nodeState* delNode = m_top;
		m_top = m_top->next;
		delete delNode;
		return &temp;
	}
}
