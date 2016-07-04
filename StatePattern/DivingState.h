#pragma once
#include"StandingState.h"

class CDivingState :
	public CHeroineState
{
public:
	CDivingState();
	virtual ~CDivingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	virtual void update(CHeroine& heroine);
};

