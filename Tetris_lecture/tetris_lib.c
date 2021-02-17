#include "tetris.h"
#include <windows.h>

int getKey() {
	int key = 0;

	if (kbhit()) {
		key = getch();
		if (key == 224)
			key = getch();
	}

	return key;
}

void gotoxy(int row, int column) {
	static HANDLE handle = NULL;
	COORD Pos = { column, row };

	if (!handle)
		handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(handle, Pos);
}

int checkTimer(int cTime) {
	static unsigned long oldTime = 0;
	unsigned long newTime;

	newTime = GetTickCount64();
	if ((newTime - oldTime) > cTime) {
		oldTime = newTime;
		return MY_TIME_OVER;
	}
	else {
		return MY_TIME_NOT;
	}
}

int copyGround(int(*source)[MY_WIDTH], int(*target)[MY_WIDTH]) {
	int i, j;

	for (i = 0; i < MY_HIGH; i++)
		for (j = 0; j < MY_WIDTH; j++)
			target[i][j] = source[i][j];

	return 0;
}