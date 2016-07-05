#pragma once
#include"DuckingState.h"
#include"JumpingState.h"
#include<assert.h>

class CStandingState :
	public CHeroineState
{
public:
	CStandingState();
	virtual ~CStandingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	// ���ִ� ���¿��� �������� ����.
	virtual void update(CHeroine& heroine);
	// ����
	virtual void enter(CHeroine& heroine);

};

