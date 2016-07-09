#pragma once
#include"Middle.h"

// ���� ������ Ŭ����
class CDivingState :
	public CMiddle
{
	// ������� �ð�(�ִϸ��̼� ��� �ð�)
	double m_aniTime;
	// ���� ���·� �Ѿ�� �Ǵ���?
	bool m_isChangeState;
public:
	CDivingState();
	virtual ~CDivingState();
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	virtual void update(CHeroine& heroine);
	virtual void enter(CHeroine& heroine);
	virtual bool getIsChangeState() { return m_isChangeState; }
};

