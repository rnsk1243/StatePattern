#pragma once
#include<iostream>
using namespace std;
#include"StateStack.h"

enum State
{
	// ���ִ� ����
	STATE_STANDING,
	// ���� ����
	STATE_JUMPING,
	// ���帮�� ����
	STATE_DUCKING,
	// ������� ����
	STATE_DIVING
};

enum Input
{
	// B��ư
	PRESS_B,
	// �Ʒ� ��ư
	PRESS_DOWN,
	// �Ʒ� ��ư ���� ��
	RELEASE_DOWN,
	// �� ��
	PRESS_NIL
};

enum IMAGE
{
	// ���帮�� �̹���
	IMAGE_DUCK,
	// ������� �̹���
	IMAGE_DIVE,
	// ���ִ� �̹���
	IMAGE_STAND,
	// ���� �̹���
	IMAGE_JUMP
};
// ���� ������ ���� ������ ������ 
class CHeroineState;
/*
C2143 ���� ���� ';'��(��) '*'�տ� �����ϴ�.
����C4430 ���� �����ڰ� �����ϴ�. int�� �����մϴ�. ����: C++������ �⺻ int�� �������� �ʽ��ϴ�.
����C2238	';' �տ� ����ġ ���� ��ū�� �ֽ��ϴ�.
����C2334	'{' �տ� ����ġ ���� ��ū�� �ֽ��ϴ�. ����� �Լ� ������ �ǳʶݴϴ�.
�̷��� ������ ��ʰ� Ƣ�� ���´�.
class CHeroineState ���־�� �ϴ� ���� ���� ������� ��ü�� �ɹ������� �����ͼ� �������ٶ� �ε� �ϴ�.
���⼭ m_state ������ CHeroineState������ ���־����ϱ� �ʿ��ѵ�.
*/
class CStateStack;

class CHeroine
{
	// �� �ٸ� ���±��� ���⿡ �� �߰��ϸ� �ȴ�.
	// ����
	// CHeroineState * m_�Ǵٸ����±��;
	
	// ���¸� ������ ���� ��ü
	CStateStack* m_stack;
public:
	CHeroine();
	~CHeroine();
	// ���� ���°�ü�� �ּҸ� ��Ƽ� ����Ű�� ���� ����
	// ������ �ϴ°��� ���� ���±��
	// ���¿� �´� ���°�ü(�ּ�)�� ��� �� ���°�ü �ȿ��ִ� �޼ҵ带 ���� ���� �ֿܼ� ��Ÿ����.
	static CHeroineState * m_state;
	// ĳ������ �⺻����(Idle)�� �Ź� ���� new ��ü�� ����� cpu���� �ǹǷ� �������� �����ΰ� ��� ��� �Ѵ�. 
	static CHeroineState* m_standingState;
	// Ű���� �Է��� �޾� Input �������� �ϳ��� ��ȯ
	Input command();
	// IMAGE�������� ���� �˸��� �̹��� ��ȯ
	void setGraphics(int command);
	// ���ۺ� ���ʰ� ���帰 ���¸� �����ؾ� �� �� �ִ�.
	void superBomb();
	// ���� ���� ��ü�� ����Ű�� �ּ� ������
	//CHeroineState* getState() { return m_state; }
	// �Է¿� ���� ���� ��ü�� �ּҸ� ����Ű�� ��ü �ּҸ� ��ȯ ��.
	void handleInput(Input input);
	// �� ���¸��� �ִ���� �ð��� ���� �ڵ� ���±�ü
	void autoStateChange();
};

//#include"StandingState.h"


