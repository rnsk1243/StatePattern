#include "DuckingState.h"

enum Time
{
	// 충전량이 3이면 특별한 기술을 사용 할 수 있다.
	MAX_CHARGE = 30
};

CDuckingState::CDuckingState() :m_chargeTime(0), m_isChangeState(false) {}


CDuckingState::~CDuckingState() {}

CHeroineState* CDuckingState::handleInput(CHeroine & heroine, int input)
{
	// 땅속이고 엎드린 상태일때만 전환 가능한 상태
	// 엎드리기 해제 이면
	if (input == RELEASE_DOWN)
	{
		// 서있는 이미지로 상태를 바꾼다.
		//heroine.setGraphics(IMAGE_STAND);
		// 서있게 되면 차지타임 초기화
		m_chargeTime = 0;
		// 엎드리기 해제 명령에의해서 서있는 상태  객체를 만들어 그 주소를 리턴함.
		cout << "DuckingState : 엎드리기 해제" << endl;
		// 충전 그만하고 돌아 갑시다
		m_isChangeState = true;
		// 스택이 비어 있으면 autoStateChange()메소드에서 자동으로 서있는 상태로 전환 하므로 nullptr을 리턴합니다.
		return nullptr; // new CStandingState(); //<< 물론 이렇게 해도 되지만 cpu낭비하며 객체를 새로 생성 할 필요는 없다.
		//return CHeroine::m_standingState; <<- 이렇게 정적 객체를 리턴해도 된다.
	}
	else {
		//m_isChangeState = true;
		return CUnderGround::handleInput(heroine, input);
	}
	// 엎드리기 해제 명령 이외의 명력은 다 nullptr을 리턴하여 상태를 바꾸지 않고 유지함.
	//return nullptr;
	//return NULL;  이렇게 해도 된다.
}

void CDuckingState::update(CHeroine & heroine)
{
	// 엎드린상태에서는 충전량이 증가한다.
	cout << "궁극기 충전중... : " << m_chargeTime << endl;
	m_chargeTime++;
	if (m_chargeTime > MAX_CHARGE) {
		// 특별기술 발동!
		heroine.superBomb();
		// 발동후 다시 0으로.
		m_chargeTime = 0;
		// 이전 상태로 돌아가는 상태변화 스택 pop 해도 좋아요.
		m_isChangeState = true;
	}

}

void CDuckingState::enter(CHeroine & heroine)
{
	cout << "궁극기를 충전 합니다." << endl;
	heroine.setGraphics(IMAGE_DUCK);
}
