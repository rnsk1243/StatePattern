#include "Middle.h"
#include"StandingState.h"


CMiddle::CMiddle()
{
}


CMiddle::~CMiddle()
{
}

CHeroineState * CMiddle::handleInput(CHeroine & heroine, int input)
{

	if (input == RELEASE_DOWN)
	{
		return new CStandingState();
	}

	return nullptr;
}

void CMiddle::update(CHeroine & heroine)
{
	cout << "중간update" << endl;
}

void CMiddle::enter(CHeroine & heroine)
{
	cout << "중간enter" << endl;
}
