#include <stdio.h>
#include "graphics.h"

#include "drawBoard.h"
#include "getUserTurn.h"

int main() {
	char board[6][6] = { {'w','w',0,'b','w','b'} ,{0,0,0,'b','w','b'}, {'b','b','w','b','w','b'} };

	initwindow(530, 530, "Pentagol!");
	drawBoard(board);

	int wid = getcurrentwindow();
	//showPointer(1, 1);

	getUserTurn(board,'b');

	while (!kbhit())
	{
		delay(400);
	}
	return 0;
}