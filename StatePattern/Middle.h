#pragma once
#include "HeroineState.h"
class CMiddle :
	public CHeroineState
{
public:
	CMiddle();
	virtual ~CMiddle();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	// ���ִ� ���¿��� �������� ����.
	virtual void update(CHeroine& heroine);
	// ����
	virtual void enter(CHeroine& heroine);
};

