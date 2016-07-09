#pragma once
//#include"JumpingState.h"
#include"HeroineState.h"

class CHeroine;


class COnGroundState :
	public CHeroineState
{
public:
	COnGroundState();
	virtual ~COnGroundState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
};

