#pragma once
#include<assert.h>
#include"OnGroundState.h"

class CStandingState :
	public COnGroundState
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

