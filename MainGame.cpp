#include "MainGame.h"


class MainGame
{
	void Start();
	void gotoXY(int x, int y);
	void MainInit();
	void MainScreen();
	//void StartInit();
	int MenuSelect();
};

int main() {
	menuNum = MAIN;
	MainInit(menuNum);
	MenuSelect();
}

void Start()
{
	cout << "\n시작화면 이동함";
	
}

void Screen(int statusnum) {
	switch (statusnum)
	{
		case MAIN:
			cout << setw(68) << "。.。:+* ゜ ゜゜ *+:。.。:+* ゜ ゜゜ *+:。.。.。:+* ゜ ゜゜*+:。。.。:\n";
			cout << setw(68) << "                            ▄▀▄     ▄▀▄                             \n";
			cout << setw(68) << "                           ▄█░░▀▀▀▀▀░░█▄                            \n";
			cout << setw(68) << "                       ▄▄  █░░░░░░░░░░░█  ▄▄                        \n";
			cout << setw(68) << "                      █▄▄█ █░░▀░░┬░░▀░░█ █▄▄█                       \n";
			cout << setw(68) << "。.。:+* ゜ ゜゜ *+:。.。:+* ゜ ゜゜ *+:。.。.。:+* ゜ ゜゜*+:。。.。:\n"
				<< endl;

			cout << setw(68) << "    ####     ##      #####           ####     ##     #    #   ######\n";
			cout << setw(68) << "   ##  ##   #  #       #            ##  ##   #  #    ##  ##   #     \n";
			cout << setw(68) << "  ##       #    #      #           ##       #    #   # ## #   #     \n";
			cout << setw(68) << "  ##       ######      #           ##  ###  ######   # ## #   ##### \n";
			cout << setw(68) << "  ##       #    #      #           ##   ##  #    #   #    #   #     \n";
			cout << setw(68) << "   ##  ##  #    #      #            ## ###  #    #   #    #   #     \n";
			cout << setw(68) << "    ####   #    #      #             ### #  #    #   #    #   ######\n\n";
			cout << "。.。:+* ゜ ゜゜ *+:。.。:+* ゜ ゜゜ *+:。.。.。:+* ゜ ゜゜*+:。。.。:\n\n";
			menuNum++;
			break;

		case START:
			break;
	}
}
void MainInit(int currentstatus) {
	SetWindowTextW(GetConsoleWindow(), L"고양이 키우기");
	system("mode con cols=70 lines=23");
	Screen(currentstatus);
}

void gotoXY(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
	// 커서 숨기기
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; // 0 : 숨기기
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(handle, &ConsoleCursor);
}

int MenuSelect() {
	int input;
	int x = 26, y = 17;
	gotoXY(x-2, y);
	cout << "▶ [  시작하기  ]\n";
	gotoXY(x, y+1);
	cout << " [  불러오기  ]\n";
	gotoXY(x, y+2);
	cout << " [  종료하기  ]\n";
	gotoXY(x, y+4);
	cout << "  Enter 누르기";
	// 키 입력 시 공통 복합키워드 224를 한 번 받고,
	input = _getch();
	while (true)
	{
		// 그 다음 방향키 값을 다시 input에 저장
		input = _getch();

		switch (input)
		{
		case UP:
			if (y > 17) {
				gotoXY(x-2, y);
				cout << "  ";
				gotoXY(x-2, --y);
				menuNum--;
				cout << "▶";
			}
			break;
		case DOWN:
			if (y < 19) {
			gotoXY(x-2, y);
			cout << "  ";
			gotoXY(x-2, ++y);
			menuNum++;
			cout << "▶";
			}
			break;
		case ENTER:
			system("cls");
			switch (menuNum)
			{
			case START:
				Start();
				break;
			case LOAD:
				cout << "불러오기는 아직";
				break;
			case QUIT:
				return 0;
			}
		}
	}
}

class StartGame : public MainGame
{
public:

};