#include <stdio.h>
#include "graphics.h"

#include "constants.h"
#include "drawBoard.h"
#include "getUserTurn.h"
#include "rotateArea.h"
#include "gameLogic.h"

int main() {
	char board[BOARD_SIZE][BOARD_SIZE] = { 0 };

	//char board[6][6] = { {'w','w',0,'b','w','b'} ,{0,0,0,'b','w','b'}, {'b','b','w','b','w','b'} };

	initwindow(1000, 530, "Pentagol!");
	int wid = getcurrentwindow();


	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 5);
	outtextxy(520, 50, "PENTAGOL!");
	
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
	outtextxy(520, 100, "Steps:");
	outtextxy(520, 120, "1. choose a point");
	outtextxy(520, 140, "2. choose a plate to rotate");
	outtextxy(520, 160, "3. choose the direction of");
	outtextxy(565, 180, "rotation");


	char gameResult;
	int area=0;

	while (TRUE) {
		drawBoard(board);
		gameResult = checkGame(board);
		if (gameResult != 'N') break;
		getUserTurn(board, 'b');
		drawBoard(board);
		area = getArea();
		rotateArea(board, area, getDirection(area));
		drawBoard(board);
		gameResult = checkGame(board);
		if (gameResult != 'N') break;
		getUserTurn(board, 'w');
		drawBoard(board);
		area = getArea();
		rotateArea(board, area, getDirection(area));
		drawBoard(board);
	}

	if (gameResult == 'F') {
		printf("NO ONE WON!");
		settextstyle(COMPLEX_FONT, HORIZ_DIR, 6);
		setcolor(LIGHTCYAN);
		outtextxy(520, 220, " NO ONE WON!  ");
		outtextxy(520, 280, "                              ");
		outtextxy(520, 300, "                              ");
		outtextxy(520, 320, "                              ");
	}
	else if (gameResult == 'B') {
		printf("BOTH PLAYERS WON!");
		settextstyle(COMPLEX_FONT, HORIZ_DIR, 6);
		setcolor(LIGHTCYAN);
		outtextxy(520, 220, "BOTH PLAYERS WON!");
		outtextxy(520, 280, "                              ");
		outtextxy(520, 300, "                              ");
		outtextxy(520, 320, "                              ");
	}
	else {
		settextstyle(COMPLEX_FONT, HORIZ_DIR, 6);
		setcolor(LIGHTCYAN);
		outtextxy(520, 220, (gameResult=='w' ? "THE WHITE      " : "THE BLACK      "));
		outtextxy(520, 270, "PLAYER WON!     ");
		outtextxy(520, 320, "                              ");
	}


	
	


	while (!kbhit())
	{
		delay(400);
	}
	return 0;
}