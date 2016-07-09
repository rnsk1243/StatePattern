#pragma once
#include"Heroine.h"
// ���� �������̽�
// ���¿� �����ϴ� ��� �ڵ�, 
// �� ���� ���ù��� �ִ� ������ �������̽��� ���� �޼���� �����(128p)

// CHeroineState Ŭ�������� CHeroine��ü�� �Ű������� ����ϰ� �����Ƿ� ������ �ʿ��ϴ�.
class CHeroine;

// ��� ����Ŭ������ �θ�Ŭ����(�������̽�)
class CHeroineState
{
public:
	CHeroineState();
	virtual ~CHeroineState();
	// �������� ���°�ü�� ���ʰ� �Ǵ� �޼���. 
	// �� Ŭ������ ��ӹ޾� ������ �Ǿ� �������� ���¿� ���� �Է°��� �޾� �˸��� ���¸� ���� ��Ų��.
	// ������ ���� �ι�° �Ķ���� int input�� ������(enum)�� �����صξ��ٰ� Input input �̷��� ���������� �ϸ� �ȵȴ�.
	// ���� ����: �ĺ��� 'Input' �̷� ������ �߻���. 
	// �������� �� �� �ִ� ���� Input�������� ����&�ʱ�ȭ ���� Heroine.h���ε� �ϴ�.
	virtual CHeroineState* handleInput(CHeroine& heroine, int input) { return nullptr; }
	// handleInput�� ��������
	virtual void update(CHeroine& heroine) {}
	virtual void enter(CHeroine& heroine) {}
	// 
	virtual bool getIsChangeState() { return nullptr; }
};

