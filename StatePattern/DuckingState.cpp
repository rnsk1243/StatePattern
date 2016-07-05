#include "DuckingState.h"

enum Time
{
	// 충전량이 3이면 특별한 기술을 사용 할 수 있다.
	MAX_CHARGE = 3
};

CDuckingState::CDuckingState() :m_chargeTime(0) {}


CDuckingState::~CDuckingState() {}

CHeroineState* CDuckingState::handleInput(CHeroine & heroine, int input)
{
	// 엎드리기 해제 이면
	if (input == RELEASE_DOWN)
	{
		// 서있는 이미지로 상태를 바꾼다.
		//heroine.setGraphics(IMAGE_STAND);
		// 서있게 되면 차지타임 초기화
		m_chargeTime = 0;
		// 엎드리기 해제 명령에의해서 서있는 상태  객체를 만들어 그 주소를 리턴함.
		return new CStandingState();
	}
	// 엎드리기 해제 명령 이외의 명력은 다 nullptr을 리턴하여 상태를 바꾸지 않고 유지함.
	return nullptr;
	//return NULL;  이렇게 해도 된다.
}

void CDuckingState::update(CHeroine & heroine)
{
	// 엎드린상태에서는 충전량이 증가한다.
	m_chargeTime++;
	if (m_chargeTime > MAX_CHARGE) {
		// 특별기술 발동!
		heroine.superBomb();
		// 발동후 다시 0으로.
		m_chargeTime = 0;
	}
}

void CDuckingState::enter(CHeroine & heroine)
{
	heroine.setGraphics(IMAGE_DUCK);
}
