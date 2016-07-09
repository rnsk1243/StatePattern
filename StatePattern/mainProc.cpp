#include"Heroine.h"
#include"HeroineState.h"
#include<Windows.h>

// 스레드생성에(CHeroineState 클래스의 update메소드 호출) 필요한 파라미터
struct ARGS
{
	// update의 파라미터로 들어갈 히로인 객체
	// &을 붙여주여야 엉뚱한 곳을 찾지 않고 내가 생성한 객체를 잘 찾아간다.(추측)
	// 만약 &을 붙여주지 않으면 프로그램이 죽지는 않으나 내가 원하는 update메소드가 호출되지 않음
	CHeroine& hero;
	// 다양한 상태들의 부모 클래스를 선언하여 이 클래스를 상속받은 모든 클래스의 update메소드를 호출 할 수 있음
	//CHeroineState* state; // state를 정적변수로 바꾸면서 더이상 필요가 없어졌다.
};

// 업데이트 호출 스레드
DWORD WINAPI updateThread(LPVOID arg)
{
	//cout << "스레드 생성 됨" << endl;
	while (true)
	{
		// 구조체 주소를 담을 pArgs변수를 선언하고 파라미터로 들어온 arg를 ARGS구조체 주소형으로 바꾸어줌
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // 주소 찍어봄
		// 구조체로 들어온 파라미터를 이용하여 update메소드 호출 
		// 이때 구조체의 CHeroineState객체를 플레이어 상태가 바뀔때마다 그에 맞는 상태로 바꿔주어서 그 상태에 맞는 update메소드를 호출하게 만듬.
		// 예) 점프 상태에서는 점프상태 객체를 state에 넣어서 점프상태 클래스의 update메소드를 호출함.
		CHeroine::m_state->update(pArgs->hero);
		//cout << "스레드에서의 state주소값 : " << CHeroine::m_state << endl;
		pArgs->hero.autoStateChange();
		Sleep(100);
	}
}


void main()
{
	// 히로인 객체 생성
	CHeroine hero;
	// 모든 상태의 부모 클래스의 주소를 담는 변수를 만들고 CHeroine클래스의 CHeroinState 주소(현재 상태 주소)를 가지고있는
	// m_state로 초기화한다 이렇게 하면 heroState변수는 현재 상태 객체를 가리킨다.
	CHeroineState* heroState = nullptr;
	// 스레드를 담을 변수
	HANDLE hThreadUpdate = NULL;

	while (true)
	{
		// m_state을 정적으로 만들어 스레드에서 호출할때나 heroine객체에서 호출할때나 똑같은 곳을 바라 본다.
		// 알맞게 초기화된 m_state 현재 상태 객체의 주소를 넘김.
		heroState = CHeroine::m_state; //hero.getState(); // m_state의 주소를 리턴하는 녀석
		// 구조체 초기화 한다.
		ARGS args = { hero };
		// 다음과 같이 하면 오류남. 추측으로는 스레드가 이미 만들어진 상태에서 주소를 바꾸어 버리면
		// 스레드가 주소를 찾아가지 못하는듯.
		// 따라서 이미 만들어진 구조체의 state주소를 바꾸기 보다는 주소를 바꾼뒤 구조체를 초기화 해서 새로
		// 구조체를 만드는 것이다.
		//args.state = *hero.getState();
		
		// 입력마다 스레드가 만들어지지 않도록 스레드가 안만들어진 NULL일때만 통과시켜줌
		if (hThreadUpdate == NULL)
		{
			// 스레드 생성
			hThreadUpdate = CreateThread(NULL, 0, updateThread, &args, 0, NULL);
			if (hThreadUpdate == NULL)
				return;
			CloseHandle(hThreadUpdate);
		}
		//heroState->handleInput(hero, hero.command());
		// hero.command()값에 따라서 히로인클래스의 m_state가 알맞게 초기화 된다.
		hero.handleInput(hero.command());
		
	}

}