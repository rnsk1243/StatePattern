#include "Heroine.h"
#include<conio.h>
#include"StandingState.h"
#include<assert.h>

// 게일 실행 시켰을때 처음 상태를 초기화 해준다.
// 정적변수는 외부에서 초기화 해주어야함. 생성자보다 먼저 호출 되므로
// 그리고 .cpp에서 초기화 해주었는데 이유는 CStandingState()객체를 .h에서 사용할 수 없어서 (자식 객체 헤더를 부모헤더에 인클루드하면 에러 우수수 니까..
CHeroineState* CHeroine::m_standingState = new CStandingState();
CHeroineState* CHeroine::m_state = CHeroine::m_standingState;

CHeroine::CHeroine(): m_stack(new CStateStack())
{
	assert(m_state);
	//m_stack->push(new CStandingState());
	
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

	// 상태를 스택에 담기
	m_stack->push(state);

	// 만약 또다른 상태기계가 있다면 여기에 입력을 전달한다.
	// 예) CHeroineState* state2 = m_또다른상태기계->handleInput(*this, input);

	///////////////////////////// 입력을 받을때마다 즉시 상태를 바구고자 할때 만든 코드 ///////////////////////////
	/*
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
	*/
	// 최종적으로 현재상태를 반환함.
	//return m_state;
}

void CHeroine::autoStateChange()
{
	// 상태를 바꿀 준비가 되었는가? ( 또다른 입력이 들어왔거나 애니가 종료 되었을때 )
	// virtual로 만들어서 어떤 상태객체로 new 객체 초기화 했느냐에따라 알맞은 메소드가 호출된다.
	// 예) 현재상태가 점프중이다라면 점프객체의 getIsChangeState()메소드가 호출됨.
	if (m_state->getIsChangeState())
	{
		// 만약 스택이 비어있으면(idle상태)
		if (m_stack->getTop() == nullptr)
		{
			cout << "스택이 비어있습니다." << endl;
			//delete m_state;
			// 정적 객체 사용 하기.
			m_state = CHeroine::m_standingState;
			m_state->enter(*this);
		}
		else {
			//cout << m_stack->getTop()->getIsChangeState() << endl;

			//cout << "상태 교체 하겠습니다." << endl;
			//delete m_state;
			// 스택에 담아둔 다음 상태 객체주소로 바꾼다.
			m_state = m_stack->pop();
			//cout << "m_state의 주소 : " << m_state << endl;
			// 다음 상태의 시작할때 한번 실행되는 메소드.
			m_state->enter(*this);

		}
	}

}
