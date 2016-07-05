#pragma once
#include"DivingState.h"
class CJumpingState :
	public CHeroineState
{
public:
	CJumpingState();
	virtual ~CJumpingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	virtual void update(CHeroine& heroine);
	virtual void enter(CHeroine& heroine);
};

