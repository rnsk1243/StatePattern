#pragma once
#include"OnSkyState.h"

class CJumpingState :
	public COnSkyState
{
public:
	CJumpingState();
	virtual ~CJumpingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	virtual void update(CHeroine& heroine);
	virtual void enter(CHeroine& heroine);
};

