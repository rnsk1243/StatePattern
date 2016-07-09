#include "Middle.h"
#include"StandingState.h"


CMiddle::CMiddle()
{
}


CMiddle::~CMiddle()
{
}

CHeroineState * CMiddle::handleInput(CHeroine & heroine, int input)
{
	// middle클래스를 상속받은 자식 상태클래스의 else에 해당하는 상태들 특별한 상태가 아닌 중간상태이면 전환 가능한 
	// 상태들을 (정의)만든다. 
	// 다른 OnGround, OnSky, Under.. 클래스도 마찬가지.
	/*
	if (input == 자식의 if문에 걸리지 않는 입력키)
	{
		// 다음상태, 이 새로 만들어진 다음상태 객체의 주소가 스택에 저장 된다.
		return new 상태
	}else if(){}...
	*/

	return nullptr;
}
