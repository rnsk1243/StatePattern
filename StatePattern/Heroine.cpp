#include "Heroine.h"
#include<conio.h>


CHeroine::CHeroine()
{
}


CHeroine::~CHeroine()
{
}

Input CHeroine::command()
{
	char ch;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
				//b
			case 98:
				return PRESS_B;
			case 80:
				return PRESS_DOWN;
			case 72:
				return RELEASE_DOWN;
			}
			if (ch == 'q')
				break;
		}
	}
	return PRESS_NIL;
}

void CHeroine::setGraphics(int command)
{
	switch (command)
	{
	case IMAGE_DUCK:
		cout << "엎드리는 이미지 생성" << endl;
		break;
	case IMAGE_DIVE:
		cout << "내려찍는 이미지 생성" << endl;
		break;
	case IMAGE_STAND:
		cout << "서있는 이미지 생성" << endl;
		break;
	case IMAGE_JUMP:
		cout << "점프하는 이미지 생성" << endl;
		break;
	default:
		break;
	}
}

void CHeroine::superBomb()
{
	cout << "슈퍼붐 발사!!!" << endl;
}
