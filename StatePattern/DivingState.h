#pragma once
#include"OnSkyState.h"

class CDivingState :
	public COnSkyState
{
public:
	CDivingState();
	virtual ~CDivingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	virtual void update(CHeroine& heroine);
	virtual void enter(CHeroine& heroine);
};

