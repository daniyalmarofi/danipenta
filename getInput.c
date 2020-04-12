#ifndef BOARD_SIZE
#include "constants.h"
#endif

// ** this function get the input from user in console
void getUserInput(char board[][BOARD_SIZE], char turn) {

    // trying to get location of the boint
	printf("\n%c player's turn:", turn);
	int input = 0, y = 0;
	int getOK = 1;
	while (getOK) {
		y = scanf_s("%d", &input);
		// ignore if user input was "abc..." : clearBuffer
		while (getchar() != '\n');
		if (y != 1 || input < 11) {
			printf("Wrong input! Try again! :");
			continue;
		}
		getOK = 0;
		int column = input % 10;
		int row = input / 10;
		if (column > BOARD_SIZE || row > BOARD_SIZE || column < 1 || row < 1) { getOK = 1; printf("Wrong input! Try again! :"); continue; }
		if (board[row - 1][column - 1] == 0) {
			board[row - 1][column - 1] = turn;
		}
		else {
			getOK = 1; printf("This place is already taken! Try another! :");
		}
	}

    // trying to get the area to rotate
	printf("select the area to rotate:");
	int selectedArea = 0;
	getOK = 1;
	while (getOK) {
		y = scanf_s("%d", &selectedArea);
		// ignore if user input was "abc..." : clearBuffer
		while (getchar() != '\n');
		if (y != 1 || selectedArea < 1 || selectedArea>4) {
			printf("Wrong input! Try again! :");
			continue;
		}
		getOK = 0;
	}

    // trying to get the direcation of rotation
	printf("select the direction of rotate:");
	char direction;
	getOK = 1;
	while (getOK) {
		y = scanf_s("%c", &direction);
		// ignore if user input was "abc..." : clearBuffer
		while (getchar() != '\n');
		if (y != 1 || (direction != '-' && direction != '+')) {
			printf("Wrong input! Try again! :");
			continue;
		}
		getOK = 0;
	}
	// do the rotate
	rotateArea(board,selectedArea, direction);

}

// ** this function rotates the user selected area
void rotateArea(char board[][BOARD_SIZE], int area, char dircetion) {
	int iFirst, jFirst;
	if (area == 1) {
		iFirst = 0;
		jFirst = 3;
	}
	else if (area == 2) {
		iFirst = 0;
		jFirst = 0;
	}
	else if (area == 3) {
		iFirst = 3;
		jFirst = 0;
	}
	else if (area == 4) {
		iFirst = 3;
		jFirst = 3;
	}
	char temp[3][3] = { 0 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// +
			if (dircetion == '+') {
				temp[j][2 - i] = board[iFirst + i][jFirst + j];
			}
			else if (dircetion == '-') {
				temp[2 - j][i] = board[iFirst + i][jFirst + j];
			}
		}
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[iFirst + i][jFirst + j] = temp[i][j];
    
    return;
}