#pragma once
#include"Middle.h"

// 내려 찍기상태 클래스
class CDivingState :
	public CMiddle
{
	// 내려찍는 시간(애니메이션 재생 시간)
	double m_aniTime;
	// 다음 상태로 넘어가도 되는지?
	bool m_isChangeState;
public:
	CDivingState();
	virtual ~CDivingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	virtual void update(CHeroine& heroine);
	virtual void enter(CHeroine& heroine);
	virtual bool getIsChangeState() { return m_isChangeState; }
};

