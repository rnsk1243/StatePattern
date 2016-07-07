#include "OnSkyState.h"
#include"DivingState.h"
#include"StandingState.h"


COnSkyState::COnSkyState()
{
}


COnSkyState::~COnSkyState()
{
}

CHeroineState * COnSkyState::handleInput(CHeroine & heroine, int input)
{
	// 공중 상태일때이면 어떤 상태이든지 전환 할 수 있는 상태들을 여기에 if분기로 나타낸다.
	if (input == PRESS_DOWN)
	{
		// 공중 상태이면 언제든지 내려찍기 기술을 사용할 수 있다.
		return new CDivingState();
	}
	else if (input == RELEASE_DOWN)
	{
		// 공중 상태이면 언제든지 서있을 수 있다.
		
		return new CStandingState();
	}
	// 만약 if문의 어떠한 것도 통과되지 않으면 nullptr을 리턴하여 지금 상태를 유지하게 한다.
	return nullptr;
}

void COnSkyState::update(CHeroine & heroine)
{
	cout << "COnSkyState의 update 메소드 입니다." << endl;
}

void COnSkyState::enter(CHeroine & heroine)
{
	cout << "COnSkyState의 enter 메소드 입니다." << endl;
}
