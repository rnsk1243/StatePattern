#include "Heroine.h"
#include<conio.h>
#include"StandingState.h"
#include<assert.h>

CHeroine::CHeroine():m_state(new CStandingState())
{
	assert(m_state);
}


CHeroine::~CHeroine()
{
}

Input CHeroine::command()
{
	char ch;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
				//b
			case 98:
				return PRESS_B;
			case 80:
				return PRESS_DOWN;
			case 72:
				return RELEASE_DOWN;
			}
			if (ch == 'q')
				break;
		}
	}
	return PRESS_NIL;
}

void CHeroine::setGraphics(int command)
{
	switch (command)
	{
	case IMAGE_DUCK:
		cout << "엎드리는 이미지 생성" << endl;
		break;
	case IMAGE_DIVE:
		cout << "내려찍는 이미지 생성" << endl;
		break;
	case IMAGE_STAND:
		cout << "서있는 이미지 생성" << endl;
		break;
	case IMAGE_JUMP:
		cout << "점프하는 이미지 생성" << endl;
		break;
	default:
		break;
	}
}

void CHeroine::superBomb()
{
	cout << "슈퍼붐 발사!!!" << endl;
}

void CHeroine::handleInput(Input input)
{
	// 상태객체 주소를 담는 state변수를 선언하고
	// m_state(현재 상태객체를 가리키는 주소)가 handleInput 메소드를 호출하는데 파라미터로
	// *this는 CHeroine자신 객체와 사용자가 입력하는 값에 따라 알맞은 상태 객체 주소를 반환한다.
	// m_state가 현재 가리키고 있는 상태 객체의 handleInput메소드를 호출한다.
	// 모든 상태 객체는 CHeroineState를 상속받았기때문에 CHeroineState 형태의 변수에 초기화 할 수 있다.
	CHeroineState* state = m_state->handleInput(*this, input);
	// 만약 또다른 상태기계가 있다면 여기에 입력을 전달한다.
	// 예) CHeroineState* state2 = m_또다른상태기계->handleInput(*this, input);

	// 만약 상태가 존재하면(새로운 입력에의해 초기화 되면)
	if (state != NULL)
	{
		// 지금 상태를 지워버리고(상태를 바꾸어야하니까)
		delete m_state;
		// 방금 초기화된 따끈따끈한 현재상태로 초기화 해준다.
		m_state = state;
		// 따끈한 현재 상태 클래스에서 현재 상태 이미지로 변경 
		// 이렇게 해주면 이전 상태에서 따끈한 다음 상태로 넘어갈때 이미지를 변경 해줄 필요가 없다.
		// 예) DuckingState.cpp에서 handleInput메소드에서 상태를 바꾸는데 이때 서있는 이미지로 상태를 바꿔줄 필요가 없어진다.
		// 이제 상태를 변경하면 그 상태가 그래픽 이미지까지 자동으로 챙겨준다.
		m_state->enter(*this);
	}
	// 최종적으로 현재상태를 반환함.
	//return m_state;
}
