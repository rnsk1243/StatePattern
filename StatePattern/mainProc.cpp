#include"Heroine.h"
#include"HeroineState.h"
#include<Windows.h>

// �����������(CHeroineState Ŭ������ update�޼ҵ� ȣ��) �ʿ��� �Ķ����
struct ARGS
{
	// update�� �Ķ���ͷ� �� ������ ��ü
	// &�� �ٿ��ֿ��� ������ ���� ã�� �ʰ� ���� ������ ��ü�� �� ã�ư���.(����)
	// ���� &�� �ٿ����� ������ ���α׷��� ������ ������ ���� ���ϴ� update�޼ҵ尡 ȣ����� ����
	CHeroine& hero;
	// �پ��� ���µ��� �θ� Ŭ������ �����Ͽ� �� Ŭ������ ��ӹ��� ��� Ŭ������ update�޼ҵ带 ȣ�� �� �� ����
	CHeroineState& state;
};

// ������Ʈ ȣ�� ������
DWORD WINAPI updateThread(LPVOID arg)
{
	cout << "������ ���� ��" << endl;
	while (true)
	{
		// ����ü �ּҸ� ���� pArgs������ �����ϰ� �Ķ���ͷ� ���� arg�� ARGS����ü �ּ������� �ٲپ���
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // �ּ� ��
		// ����ü�� ���� �Ķ���͸� �̿��Ͽ� update�޼ҵ� ȣ�� 
		// �̶� ����ü�� CHeroineState��ü�� �÷��̾� ���°� �ٲ𶧸��� �׿� �´� ���·� �ٲ��־ �� ���¿� �´� update�޼ҵ带 ȣ���ϰ� ����.
		// ��) ���� ���¿����� �������� ��ü�� state�� �־ �������� Ŭ������ update�޼ҵ带 ȣ����.
		pArgs->state.update(pArgs->hero);
		Sleep(1000);
	}
}


void main()
{
	// ������ ��ü ����
	CHeroine hero;
	// ��� ������ �θ� Ŭ������ �ּҸ� ��� ������ ����� CHeroineŬ������ CHeroinState �ּ�(���� ���� �ּ�)�� �������ִ�
	// m_state�� �ʱ�ȭ�Ѵ� �̷��� �ϸ� heroState������ ���� ���� ��ü�� ����Ų��.
	CHeroineState* heroState = hero.getState();
	// �����带 ���� ����
	HANDLE hThreadUpdate = NULL;

	while (true)
	{
		//heroState->handleInput(hero, hero.command());
		// hero.command()���� ���� ������Ŭ������ m_state�� �˸°� �ʱ�ȭ �ȴ�.
		hero.handleInput(hero.command());
		// �˸°� �ʱ�ȭ�� m_state ���� ���� ��ü�� �ּҸ� �ѱ�.
		heroState = hero.getState();
		// ����ü �ʱ�ȭ �Ѵ�.
		ARGS args = { hero, *heroState };
		// ������ ���� �ϸ� ������. �������δ� �����尡 �̹� ������� ���¿��� �ּҸ� �ٲپ� ������
		// �����尡 �ּҸ� ã�ư��� ���ϴµ�.
		// ���� �̹� ������� ����ü�� state�ּҸ� �ٲٱ� ���ٴ� �ּҸ� �ٲ۵� ����ü�� �ʱ�ȭ �ؼ� ����
		// ����ü�� ����� ���̴�.
		//args.state = *hero.getState();
		
		// �Է¸��� �����尡 ��������� �ʵ��� �����尡 �ȸ������ NULL�϶��� ���������
		if (hThreadUpdate == NULL)
		{
			// ������ ����
			hThreadUpdate = CreateThread(NULL, 0, updateThread, &args, 0, NULL);
			if (hThreadUpdate == NULL)
				return;
			CloseHandle(hThreadUpdate);
		}

		
	}

}