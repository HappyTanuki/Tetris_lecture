#include <stdio.h>
#include "tetris.h"

extern Point		current;

extern int			curBlock;
extern int			curDir;

extern int			basGround[MY_HIGH][MY_WIDTH];
extern int			disGround[MY_HIGH][MY_WIDTH];
extern int			preGround[MY_HIGH][MY_WIDTH];

extern Point		(*blockPattern[MY_PATTERN_NUM])[4];
extern int			blockColor[MY_PATTERN_NUM];

int main() {
	init();

	current.row = 1;
	current.column = 7;

	curBlock = 0;
	curDir = 0;

	copybasGroundTodisGround();
	displayGround();

	return 0;
}