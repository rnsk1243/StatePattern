#pragma once
// 다 똑같은 상태 객체인데 CDuckingState에서는
// 이 HeroineState.h 을 include하지 않는 순간 에러가 백개넘게 발생한다.
// 왜 이 클래스만 이 헤더를 요구하는지 정확한 이유는 모르겠지만.
// 다른 상태 객체와 다른 점은 필드에 int형의 멤버변수가 존재 한다.
#include "HeroineState.h"
#include"StandingState.h"

class CDuckingState :
	public CHeroineState
{
	// 엎드린 상태로 전환 뒤에 충전 시간.
	// 스레드에 의해 update메소드가 호출되어 증가한다.
	int m_chargeTime;
public:
	CDuckingState();
	virtual ~CDuckingState();
	// input명령에 따른 상태 객체를 새로 만들어서 만들어진 주소를 반환함.
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	// 엎드린 상태에서 히로인이 할 일 정의
	virtual void update(CHeroine& heroine);

};

