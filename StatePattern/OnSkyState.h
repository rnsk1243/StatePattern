#pragma once
#include"HeroineState.h"

class COnSkyState :
	public CHeroineState
{
public:
	COnSkyState();
	virtual ~COnSkyState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	virtual void update(CHeroine& heroine);
	virtual void enter(CHeroine& heroine);
};

