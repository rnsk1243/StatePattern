#pragma once
#include "HeroineState.h"
// 땅도 아니고 완전 공중 상태도 아닐때
// 예) 점프하고 내려찍는 상태
class CMiddle :
	public CHeroineState
{
public:
	CMiddle();
	virtual ~CMiddle();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
};

