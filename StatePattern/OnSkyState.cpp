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
	// ���� �����϶��̸� � �����̵��� ��ȯ �� �� �ִ� ���µ��� ���⿡ if�б�� ��Ÿ����.
	if (input == PRESS_DOWN)
	{
		// ���� �����̸� �������� ������� ����� ����� �� �ִ�.
		return new CDivingState();
	}
	else if (input == RELEASE_DOWN)
	{
		// ���� �����̸� �������� ������ �� �ִ�.
		
		return new CStandingState();
	}
	// ���� if���� ��� �͵� ������� ������ nullptr�� �����Ͽ� ���� ���¸� �����ϰ� �Ѵ�.
	return nullptr;
}

void COnSkyState::update(CHeroine & heroine)
{
	cout << "COnSkyState�� update �޼ҵ� �Դϴ�." << endl;
}

void COnSkyState::enter(CHeroine & heroine)
{
	cout << "COnSkyState�� enter �޼ҵ� �Դϴ�." << endl;
}
