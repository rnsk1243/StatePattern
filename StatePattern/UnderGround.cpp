#include "UnderGround.h"
#include"StandingState.h"


CUnderGround::CUnderGround()
{
}


CUnderGround::~CUnderGround()
{
}

CHeroineState * CUnderGround::handleInput(CHeroine & heroine, int input)
{
	// ���ӻ��¶�� �������� ���ִ� ���·� �� �� �ִ�.
	if (input == RELEASE_DOWN)
	{
		return new CStandingState();
	}
	return nullptr;
}
