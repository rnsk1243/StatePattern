#pragma once
#include<iostream>
using namespace std;

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

class CHeroine
{
public:
	CHeroine();
	~CHeroine();
	Input command();
	void setGraphics(int command);
	void superBomb();
};

