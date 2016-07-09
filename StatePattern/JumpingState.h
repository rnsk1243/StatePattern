#pragma once
#include"OnSkyState.h"

class CJumpingState :
	public COnSkyState
{
	double m_aniTime;
	bool m_isChangeState;
public:
	CJumpingState();
	virtual ~CJumpingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	virtual void update(CHeroine& heroine);
	virtual void enter(CHeroine& heroine);
	virtual bool getIsChangeState() { //cout << "점프상태의 getIs" << endl; 
	return m_isChangeState; }
};

