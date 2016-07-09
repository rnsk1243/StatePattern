#pragma once
#include"HeroineState.h"

class CHeroineState;

struct nodeState
{
	// 상태객체 주소를 담을 변수
	CHeroineState* itemState;
	// 다음 상태객체
	nodeState* next;
};
// 상태를 담을 스택(괜히 쓸대없이 링크드리스트로 만들었다.)
class CStateStack
{
	// 가장 위에있는 객체를 가리키는 주소를 담는 변수
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

