#include <stdio.h>
#include "graphics.h"
#include "drawBoard.h"
#include "getUserTurn.h"
#include "rotateArea.h"

int main() {
	char board[6][6] = { {'w','w',0,'b','w','b'} ,{0,0,0,'b','w','b'}, {'b','b','w','b','w','b'} };

	initwindow(530, 530, "Pentagol!");
	drawBoard(board);

	int wid = getcurrentwindow();
	
	getUserTurn(board,'b');
	
	drawBoard(board);

	getDirection(4);
	//int area = getArea();
	//rotateArea(board,area,getDirection(area));

	while (!kbhit())
	{
		delay(400);
	}
	return 0;
}