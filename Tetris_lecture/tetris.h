#ifndef _TETRIS_H
#define _TETRIS_H

#define MY_PATTERN_NUM		7
#define MY_HIGH				25
#define MY_WIDTH			15

#define MY_DELAY_TIME		1000
#define MY_MIN_DELAY		100


#define MY_SPACE			0x0F
#define MY_WALL				0xF0
#define MY_BLOCK_1			0
#define MY_BLOCK_2			1
//#define MY_BLOCK_3			2
//#define MY_BLOCK_4			3
//#define MY_BLOCK_5			4

//#define MY_BASE_BLOCK	9


#define MY_KEY_UP			72
#define MY_KEY_DOWN			80
#define MY_KEY_RIGHT		77
#define MY_KEY_LEFT			75
#define MY_KEY_SPACE		32
#define MY_KEY_PAUSE		'P'	
#define MY_KEY_RESET		'R'
#define MY_KEY_STOP			'Q'

#define MY_MOVE_ON			1
#define MY_MOVE_NOT			0
#define MY_GAME_OVER		1
#define MY_GAME_NOT			0
#define MY_TIME_OVER		1
#define MY_TIME_NOT			0

typedef struct _Point{
	int row;			//За
	int column;			//ї­
} Point;

int		getKey();
void	gotoxy(int row, int column);
int		checkTimer(int cTime);
int		copyGround(int (*source)[MY_WIDTH], int (*target)[MY_WIDTH]);

void	init();
void	copybasGroundTodisGround();
void	displayGround();
void	checkChangeBlock(int key, Point *cur, int *dir);
int		changeBlock(Point cur, int dir);

#endif