#pragma once
#include "HeroineState.h"
// ���� �ƴϰ� ���� ���� ���µ� �ƴҶ�
// ��) �����ϰ� ������� ����
class CMiddle :
	public CHeroineState
{
public:
	CMiddle();
	virtual ~CMiddle();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
};

