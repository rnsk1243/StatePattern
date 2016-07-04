#include"Heroine.h"
#include"HeroineState.h"
#include"DuckingState.h"
#include<Windows.h>

struct ARGS
{
	CHeroine& hero;
	CHeroineState& state;
};

DWORD WINAPI updateThread(LPVOID arg)
{
	while (true)
	{
		ARGS* pArgs = (ARGS*)arg;
		pArgs->state.update(pArgs->hero);
		Sleep(100);
	}
}


void main()
{

	CHeroine hero;

	CHeroineState* heroState = new CDuckingState();

	ARGS args = { hero, *heroState };

	HANDLE hThreadUpdate = CreateThread(NULL, 0, updateThread, &args, 0, NULL);
	if (hThreadUpdate == NULL)
		return;
	CloseHandle(hThreadUpdate);

	while (true)
	{
		heroState->handleInput(hero, hero.command());
	}

}