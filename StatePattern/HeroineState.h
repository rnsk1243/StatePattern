#pragma once
#include"Heroine.h"
// ���� �������̽�
// ���¿� �����ϴ� ��� �ڵ�, �� ���� ���ù��� �ִ� ������ �������̽��� ���� �޼���� �����(128p)
class CHeroineState
{
public:
	CHeroineState();
	virtual ~CHeroineState();
	// 
	virtual void handleInput(CHeroine& heroine, Input input) {}
	//
	virtual void update(CHeroine& heroine) {}
};

