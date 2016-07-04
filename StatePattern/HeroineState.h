#pragma once
#include"Heroine.h"
// 상태 인터페이스
// 상태에 의존하는 모든 코드, 즉 다중 선택문에 있던 동작을 인터페이스의 가상 메서드로 만든다(128p)
class CHeroineState
{
public:
	CHeroineState();
	virtual ~CHeroineState();
	// 
	virtual void handleInput(CHeroine& heroine, Input input) {}
	//
	virtual void update(CHeroine& heroine) {}
};

