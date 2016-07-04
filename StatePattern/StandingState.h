#pragma once
#include "HeroineState.h"
class CStandingState :
	public CHeroineState
{
public:
	CStandingState();
	virtual ~CStandingState();
	virtual void handleInput(CHeroine& heroine, Input input);
	virtual void update(CHeroine& heroine);
};

