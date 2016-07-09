#pragma once
#include"HeroineState.h"

class CHeroineState;

struct nodeState
{
	// ���°�ü �ּҸ� ���� ����
	CHeroineState* itemState;
	// ���� ���°�ü
	nodeState* next;
};
// ���¸� ���� ����(���� ������� ��ũ�帮��Ʈ�� �������.)
class CStateStack
{
	// ���� �����ִ� ��ü�� ����Ű�� �ּҸ� ��� ����
	nodeState* m_top;
public:
	CStateStack();
	~CStateStack();
	CHeroineState* getTop() 
	{ 
		if (!isEmpty())
		{
			return m_top->itemState;
		}
		else {
			return nullptr;
		}
	}
	void push(CHeroineState* state);
	CHeroineState* pop();
	bool isEmpty() { return m_top == nullptr ? true : false; }
};

