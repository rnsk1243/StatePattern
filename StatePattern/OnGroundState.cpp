#include "OnGroundState.h"
#include"DuckingState.h"
#include"JumpingState.h"

COnGroundState::COnGroundState()
{
}


COnGroundState::~COnGroundState()
{
}

CHeroineState * COnGroundState::handleInput(CHeroine & heroine, int input)
{
	//점프
	if (input == PRESS_B)
	{
		//cout << "점프상태로 전환 합니다." << endl;
		return new CJumpingState();
	}// 엎드리기
	else if (input == PRESS_DOWN)
	{
		//cout << "엎드리기 상태로 전환 합니다." << endl;
		return new CDuckingState();
	}

	return nullptr;
}

void COnGroundState::update(CHeroine & heroine)
{
	cout << "OnGroundState의 update 메소드 입니다." << endl;
}

void COnGroundState::enter(CHeroine & heroine)
{
	cout << "OnGroundState의 enter 메소드 입니다." << endl;
}
