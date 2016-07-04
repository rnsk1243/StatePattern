#pragma once
#include "HeroineState.h"
class CJumpingState :
	public CHeroineState
{
public:
	CJumpingState();
	virtual ~CJumpingState();
	virtual void handleInput(CHeroine& heroine, Input input);
	virtual void update(CHeroine& heroine);
};

