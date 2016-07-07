#pragma once
#include"HeroineState.h"

struct nodeState
{
	CHeroineState* itemState;
	nodeState* next;
};

class CStateStack
{
	nodeState* m_top;
public:
	CStateStack();
	~CStateStack();
	void push(CHeroineState* state);
	CHeroineState* pop();
	bool isEmpty() { m_top == nullptr ? true : false; }
};

