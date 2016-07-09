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
	// 공중 상태에서 공통으로 전 환 할 수 있는 상태
	//if (input == 입력키)
	//{
		
	//}
	// 만약 if문의 어떠한 것도 통과되지 않으면 nullptr을 리턴하여 서있기 상태로 간다.(이유 스택이 비면 서있기로 했으니까)
	//cout << "null 리턴함" << endl;
	return nullptr;
}


