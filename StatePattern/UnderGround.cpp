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
	// 땅속상태라면 언제든지 서있는 상태로 갈 수 있다.
	if (input == RELEASE_DOWN)
	{
		return new CStandingState();
	}
	return nullptr;
}
