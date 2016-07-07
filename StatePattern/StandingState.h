#pragma once
#include<assert.h>
#include"OnGroundState.h"

class CStandingState :
	public COnGroundState
{
public:
	CStandingState();
	virtual ~CStandingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	// 서있는 상태에서 히로인이 할일.
	virtual void update(CHeroine& heroine);
	// 입장
	virtual void enter(CHeroine& heroine);

};

