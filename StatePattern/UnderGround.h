#pragma once
#include "HeroineState.h"

class CUnderGround :
	public CHeroineState
{

public:
	CUnderGround();
	virtual ~CUnderGround();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	// ���ִ� ���¿��� �������� ����.
	//virtual void update(CHeroine& heroine);
	// ����
	//virtual void enter(CHeroine& heroine);
};

