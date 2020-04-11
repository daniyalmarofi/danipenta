#include "graphics.h"
#include "getUserTurn.h"

int getCoordinate(int i, int j, char component) {
	if (component == 'i')
		return 90 + 70 * i;
	else if(component=='j')
		return 90 + 70 * j;
	return -1;
}

void drawBoard(char board[][6]) {

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
	line(50, 265, 480, 265);
	line(265, 50, 265, 480);

	//show row number
	for (i = 0; i < 6; i++) {
		char number[2];
		sprintf(number, "%d", i + 1);
		outtextxy(80 + 70 * i, 30, number);
	}

	//show column number
	for (i = 0; i < 6; i++) {
		char number[2];
		sprintf(number, "%d", i + 1);
		outtextxy(30, 80 + 70 * i, number);
	}

	//show initial board
	int fillColor;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			circle(getCoordinate(i, j, 'i'), getCoordinate(i, j, 'j'), 30);
			if (board[j][i] == 'w')
				fillColor = WHITE;
			else if (board[j][i] == 'b')
				fillColor = BLACK;
			else
				fillColor = RED;
			setfillstyle(SOLID_FILL, fillColor);
			floodfill(getCoordinate(i, j, 'i'), getCoordinate(i, j, 'j'), YELLOW);

			delay(100);
		}
	}

	return;
}

