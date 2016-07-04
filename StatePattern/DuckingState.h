#pragma once
#include "HeroineState.h"

class CDuckingState :
	public CHeroineState
{
	int m_chargeTime;
public:
	CDuckingState();
	virtual ~CDuckingState();

	// 
	virtual void handleInput(CHeroine& heroine, Input input);
	//
	virtual void update(CHeroine& heroine);

};

