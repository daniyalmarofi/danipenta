#include "graphics.h"
#include "getUserTurn.h"
#include "constants.h"

// ** This functions returns the coordinates of (i,j) point for the graphic window
int getCoordinate(int i, int j, char component) {
	if (component == 'i')
		return 90 + 70 * i;
	else if(component=='j')
		return 90 + 70 * j;
	return -1;
}

// ** this function draws the board
void drawBoard(char board[][BOARD_SIZE]) {

	int i, j;
	//int wid = ALL_WINDOWS;
	//wid = getcurrentwindow();
	GetActiveWindow();
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0xFFFF, 2);
	setcolor(YELLOW);
	rectangle(50, 50, 480, 480);
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	floodfill(55, 55, YELLOW);
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, RED);
	//draw vertical line
	line(50, 265, 480, 265);
	//draw horizontal line
	line(265, 50, 265, 480);

	//show row number
	settextstyle(SIMPLEX_FONT, HORIZ_DIR, 1);
	for (i = 0; i < BOARD_SIZE; i++) {
		char number[2];
		sprintf(number, "%d", i + 1);
		outtextxy(80 + 70 * i, 30, number);
	}

	//show column number
	for (i = 0; i < BOARD_SIZE; i++) {
		char number[2];
		sprintf(number, "%d", i + 1);
		outtextxy(30, 80 + 70 * i, number);
	}

	//show the board
	int fillColor;
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			circle(getCoordinate(i, j, 'i'), getCoordinate(i, j, 'j'), 30);
			if (board[j][i] == 'w')
				fillColor = WHITE;
			else if (board[j][i] == 'b')
				fillColor = BLACK;
			else
				fillColor = RED;
			setfillstyle(SOLID_FILL, fillColor);
			floodfill(getCoordinate(i, j, 'i'), getCoordinate(i, j, 'j'), YELLOW);
		}
	}

	return;
}

