#pragma once
#include<iostream>
using namespace std;
#include"HeroineState.h"

enum State
{
	// 서있는 상태
	STATE_STANDING,
	// 점프 상태
	STATE_JUMPING,
	// 엎드리기 상태
	STATE_DUCKING,
	// 내려찍기 상태
	STATE_DIVING
};

enum Input
{
	// B버튼
	PRESS_B,
	// 아래 버튼
	PRESS_DOWN,
	// 아래 버튼 때는 것
	RELEASE_DOWN,
	// 그 외
	PRESS_NIL
};

enum IMAGE
{
	// 엎드리는 이미지
	IMAGE_DUCK,
	// 내려찍는 이미지
	IMAGE_DIVE,
	// 서있는 이미지
	IMAGE_STAND,
	// 점프 이미지
	IMAGE_JUMP
};
// 만약 다음과 같이 해주지 않으면 
class CHeroineState;
/*
C2143 구문 오류 ';'이(가) '*'앞에 없습니다.
오류C4430 형식 지정자가 없습니다. int로 가정합니다. 참고: C++에서는 기본 int를 지원하지 않습니다.
오류C2238	';' 앞에 예기치 않은 토큰이 있습니다.
오류C2334	'{' 앞에 예기치 않은 토큰이 있습니다. 명백한 함수 본문을 건너뜁니다.
이러한 오류가 몇십개 튀어 나온다.
class CHeroineState 해주어야 하는 경우는 전혀 상관없는 객체를 맴버변수로 가져와서 선언해줄때 인듯 하다.
여기서 m_state 변수를 CHeroineState형으로 해주었으니까 필요한듯.
*/

class CHeroine
{
	// 현재 상태객체의 주소를 담아서 가리키는 변수 선언
	CHeroineState * m_state;
public:
	CHeroine();
	~CHeroine();
	// 키보드 입력을 받아 Input 열거형중 하나를 반환
	Input command();
	// IMAGE열거형에 따라 알맞은 이미지 반환
	void setGraphics(int command);
	// 슈퍼붐 5초간 엎드려야 쓸 수 있다.
	void superBomb();
	// 현제 상태 객체를 가리키는 주소 가져옴
	CHeroineState* getState() { return m_state; }
	// 입력에 따라 상태 객체의 주소를 가리키는 객체 주소를 반환 함.
	CHeroineState* handleInput(Input input);
};

