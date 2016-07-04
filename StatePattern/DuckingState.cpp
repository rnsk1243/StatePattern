#include "DuckingState.h"

enum Time
{
	MAX_CHARGE = 20
};

CDuckingState::CDuckingState() :m_chargeTime(0) {}


CDuckingState::~CDuckingState() {}

void CDuckingState::handleInput(CHeroine & heroine, Input input)
{
	// 엎드리기 해제 이면
	if (input == RELEASE_DOWN)
	{
		// 서있는 이미지
		heroine.setGraphics(IMAGE_STAND);
		// 서있게 되면 차지타임 초기화
		m_chargeTime = 0;
	}
}

void CDuckingState::update(CHeroine & heroine)
{
	m_chargeTime++;
	if (m_chargeTime > MAX_CHARGE) {
		heroine.superBomb();
		m_chargeTime = 0;
	}
}
