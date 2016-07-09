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
	/*
	// 땅속상태라면 언제든지 갈 수 있는 상태로 갈 수 있다.
	// 자식 클래스의 handleInput먼저 호출 되므로 자식 클래스의 if문 조건에 해당하지 않는 입력키를(else) 받게 합니다.
	if (input == 입력키)
	{
		return new 상태
	}
	*/
	// 널이면 서있기 상태
	return nullptr;
}
