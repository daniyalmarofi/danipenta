#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "showBoard.h"
#include "getInput.h"
#include "gameLogic.h"

#include "showBoard.c"
#include "getInput.c"
#include "gameLogic.cpp"

int main() {

    char board[BOARD_SIZE][BOARD_SIZE] = { 0 };
	char gameResult;

	while (TRUE) {
		showBoard(board);
		gameResult = checkGame(board);
		if (gameResult != 'N') break;
		getUserInput(board,'b');
		showBoard(board);
		gameResult = checkGame(board);
		if (gameResult != 'N') break;
		getUserInput(board,'w');
	}

	if (gameResult == 'F') {
		printf("NO ONE WON!");
	}
	else if (gameResult == 'B') {
		printf("BOTH PLAYERS WON!");
	}
	else {
		printf("THE PLAYER %c WON!", gameResult);
	}

	getchar();
	return 0;
}
