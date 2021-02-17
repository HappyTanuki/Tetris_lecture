#include "tetris.h"
#include <stdio.h>

extern Point		current;

extern int			curBlock;
extern int			curDir;

extern int			basGround[MY_HIGH][MY_WIDTH];
extern int			disGround[MY_HIGH][MY_WIDTH];
extern int			preGround[MY_HIGH][MY_WIDTH];

extern Point		(*blockPattern[MY_PATTERN_NUM])[4];
extern int			blockColor[MY_PATTERN_NUM];

void init() {
	int i, k;

	for (i = 0; i < MY_HIGH; i++)
		for (k = 0; k < MY_WIDTH; k++) {
			basGround[i][k] = MY_SPACE;
			preGround[i][k] = 0xFF;
		}

	for (k = 0; k < MY_WIDTH; k++) {
		basGround[0][k]				= MY_WALL;
		basGround[MY_HIGH - 1][k]	= MY_WALL;
	}

	for (i = 0; i < MY_HIGH; i++) {
		basGround[i][0]				= MY_WALL;
		basGround[i][MY_WIDTH - 1]	= MY_WALL;
	}
}

void copybasGroundTodisGround() {
	int i, row, col;

	copyGround(basGround, disGround);

	for (i = 0; i < 4; i++) {
		row = current.row		+ blockPattern[curBlock][curDir][i].row;
		col = current.column	+ blockPattern[curBlock][curDir][i].column;

		disGround[row][col] = 1;
	}
}

void displayGround() {
	int i, k;

	for (i = 0; i < MY_HIGH; i++)
		for (k = 0; k < MY_WIDTH; k++) {
			if (disGround[i][k] != preGround[i][k]) {
				gotoxy(i, 2*k);
				switch (disGround[i][k]) {
				case MY_WALL:
					printf("бр");
					break;
				case MY_SPACE:
					printf("  ");
					break;
				default:
					printf("бс");
					break;
				}
			}
		}
}