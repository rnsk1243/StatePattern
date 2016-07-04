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
		cout << "���帮�� �̹��� ����" << endl;
		break;
	case IMAGE_DIVE:
		cout << "������� �̹��� ����" << endl;
		break;
	case IMAGE_STAND:
		cout << "���ִ� �̹��� ����" << endl;
		break;
	case IMAGE_JUMP:
		cout << "�����ϴ� �̹��� ����" << endl;
		break;
	default:
		break;
	}
}

void CHeroine::superBomb()
{
	cout << "���ۺ� �߻�!!!" << endl;
}
