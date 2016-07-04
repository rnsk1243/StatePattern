#pragma once
#include "HeroineState.h"
class CDivingState :
	public CHeroineState
{
public:
	CDivingState();
	virtual ~CDivingState();
	virtual void handleInput(CHeroine& heroine, Input input);
	virtual void update(CHeroine& heroine);
};

