#pragma once
// �� �Ȱ��� ���� ��ü�ε� CDuckingState������
// �� HeroineState.h �� include���� �ʴ� ���� ������ �鰳�Ѱ� �߻��Ѵ�.
// �� �� Ŭ������ �� ����� �䱸�ϴ��� ��Ȯ�� ������ �𸣰�����.
// �ٸ� ���� ��ü�� �ٸ� ���� �ʵ忡 int���� ��������� ���� �Ѵ�.
#include "HeroineState.h"
#include"StandingState.h"
#include"UnderGround.h"

class CDuckingState :
	public CUnderGround
{
	// ���帰 ���·� ��ȯ �ڿ� ���� �ð�.
	// �����忡 ���� update�޼ҵ尡 ȣ��Ǿ� �����Ѵ�.
	int m_chargeTime;
	bool m_isChangeState;
public:
	CDuckingState();
	virtual ~CDuckingState();
	// input��ɿ� ���� ���� ��ü�� ���� ���� ������� �ּҸ� ��ȯ��.
	virtual CHeroineState* handleInput(CHeroine& heroine, int input);
	// ���帰 ���¿��� �������� ���������� �� �� ����
	virtual void update(CHeroine& heroine);
	// ���°� �ٲ��ڸ��� �� ��
	virtual void enter(CHeroine& heroine);
	virtual bool getIsChangeState() { return m_isChangeState; }
};

