#pragma once
#include"Middle.h"

class CDivingState :
	public CMiddle
{
public:
	CDivingState();
	virtual ~CDivingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	virtual void update(CHeroine& heroine);
	virtual void enter(CHeroine& heroine);
};

