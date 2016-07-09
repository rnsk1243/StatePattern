#pragma once
#include"Heroine.h"
// 상태 인터페이스
// 상태에 의존하는 모든 코드, 
// 즉 다중 선택문에 있던 동작을 인터페이스의 가상 메서드로 만든다(128p)

// CHeroineState 클래스에서 CHeroine객체를 매개변수로 사용하고 있으므로 선언이 필요하다.
class CHeroine;

// 모든 상태클래스의 부모클래스(인터페이스)
class CHeroineState
{
public:
	CHeroineState();
	virtual ~CHeroineState();
	// 여러가지 상태객체의 기초가 되는 메서드. 
	// 이 클래스를 상속받아 재정의 되어 여러가지 상태에 따라서 입력값을 받아 알맞은 상태를 리턴 시킨다.
	// 주의할 점은 두번째 파라미터 int input을 열거형(enum)을 선언해두었다고 Input input 이렇게 열거형으로 하면 안된다.
	// 구문 오류: 식별자 'Input' 이런 오류가 발생함. 
	// 열거형을 쓸 수 있는 것은 Input열거형을 선언&초기화 해준 Heroine.h뿐인듯 하다.
	virtual CHeroineState* handleInput(CHeroine& heroine, int input) { return nullptr; }
	// handleInput과 마찬가지
	virtual void update(CHeroine& heroine) {}
	virtual void enter(CHeroine& heroine) {}
	// 
	virtual bool getIsChangeState() { return nullptr; }
};

