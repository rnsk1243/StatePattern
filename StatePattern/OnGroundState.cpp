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
	//����
	if (input == PRESS_B)
	{
		//cout << "�������·� ��ȯ �մϴ�." << endl;
		return new CJumpingState();
	}// ���帮��
	else if (input == PRESS_DOWN)
	{
		//cout << "���帮�� ���·� ��ȯ �մϴ�." << endl;
		return new CDuckingState();
	}

	return nullptr;
}

