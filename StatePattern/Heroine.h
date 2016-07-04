#pragma once
#include<iostream>
using namespace std;

enum State
{
	// 서있는 상태
	STATE_STANDING,
	// 점프 상태
	STATE_JUMPING,
	// 엎드리기 상태
	STATE_DUCKING,
	// 내려찍기 상태
	STATE_DIVING
};

enum Input
{
	// B버튼
	PRESS_B,
	// 아래 버튼
	PRESS_DOWN,
	// 아래 버튼 때는 것
	RELEASE_DOWN,
	// 그 외
	PRESS_NIL
};

enum IMAGE
{
	// 엎드리는 이미지
	IMAGE_DUCK,
	// 내려찍는 이미지
	IMAGE_DIVE,
	// 서있는 이미지
	IMAGE_STAND,
	// 점프 이미지
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

