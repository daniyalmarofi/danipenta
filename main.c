#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define BOARD_SIZE 6

#include "showBoard.h"
#include "getInput.h"
#include "gameLogic.h"
char board[BOARD_SIZE][BOARD_SIZE] = { 0 };

#include "showBoard.c"
#include "gameLogic.c"
#include "getInput.c"

int main() {
	char gameResult;

	while (TRUE) {
		showBoard();
		gameResult = checkGame();
		if (gameResult != 'N') break;
		getUserInput('b');
		showBoard();
		gameResult = checkGame();
		if (gameResult != 'N') break;
		getUserInput('w');
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
