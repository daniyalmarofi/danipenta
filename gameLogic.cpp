#include "constants.h"

// ** this function checks if the user turn wins or not. returns 1 if won
int checkWinner(char board[][BOARD_SIZE], char action, int row, int col, char turn) {
	// action::
	// v = top down check
	// V = bottom up check
	// h = left right check
	// H = right left check
	// 1 = first diaginal check
	// 2 = second diagonal check
	// 3 = third diagonal check
	// 4 = forth diagonal check
	int i;
	for (i = 0; i < 4; i++) {
		switch (action) {
		case 'v':
			if (board[row + i][col] != turn) return FALSE;
			break;
		case 'V':
			if (board[row - i][col] != turn) return FALSE;
			break;
		case 'h':
			if (board[row][col + i] != turn) return FALSE;
			break;
		case 'H':
			if (board[row][col - i] != turn) return FALSE;
			break;
		case '1':
			if (board[row + i][col + i] != turn) return FALSE;
			break;
		case '2':
			if (board[row + i][col - i] != turn) return FALSE;
			break;
		case '3':
			if (board[row - i][col + i] != turn) return FALSE;
			break;
		case '4':
			if (board[row - i][col - i] != turn) return FALSE;
			break;
		}
	}
	int row1, col1, row2, col2;

	switch (action) {
	case 'v':
		row1 = 3; col1 = 1;
		row2 = 3; col2 = -1;
		break;
	case 'V':
		row1 = -3; col1 = 1;
		row2 = -3; col2 = -1;
		break;
	case 'h':
		row1 = 1; col1 = 3;
		row2 = -1; col2 = 3;
		break;
	case 'H':
		row1 = 1; col1 = -3;
		row2 = -1; col2 = -3;
		break;
	case '1':
		row1 = 4; col1 = 2;
		row2 = 2; col2 = 4;
		break;
	case '2':
		row1 = 4; col1 = -2;
		row2 = 2; col2 = -4;
		break;
	case '3':
		row1 = -4; col1 = 2;
		row2 = -2; col2 = 4;
		break;
	case '4':
		row1 = -2; col1 = -4;
		row2 = -4; col2 = -2;
		break;
	}

	if (board[row + row1][col + col1] == turn || board[row + row2][col + col2] == turn) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// ** this function check all the winning possibilities for both members
// ** returns
// * B if both won
// * N if no one won
// * b if black player won
// * w if white player won
// * F if board was full
char checkGame(char board [][BOARD_SIZE]) {

	int bWin = FALSE;
	int wWin = FALSE;
	int full = TRUE;

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {

			if (j < 3) {
				if (checkWinner(board, 'h', i, j, 'b')) bWin = TRUE;
				if (checkWinner(board, 'h', i, j, 'w')) wWin = TRUE;
			}
			else {
				if (checkWinner(board, 'H', i, j, 'b')) bWin = TRUE;
				if (checkWinner(board, 'H', i, j, 'w')) wWin = TRUE;
			}

			if (i < 3) {
				if (checkWinner(board, 'v', i, j, 'b')) bWin = TRUE;
				if (checkWinner(board, 'v', i, j, 'w')) wWin = TRUE;

				if (j < 3) {
					if (checkWinner(board, '1', i, j, 'b')) bWin = TRUE;
					if (checkWinner(board, '1', i, j, 'w')) wWin = TRUE;
				}
				else {
					if (checkWinner(board, '2', i, j, 'b')) bWin = TRUE;
					if (checkWinner(board, '2', i, j, 'w')) wWin = TRUE;
				}
			}
			else {
				if (checkWinner(board, 'V', i, j, 'b')) bWin = TRUE;
				if (checkWinner(board, 'V', i, j, 'w')) wWin = TRUE;

				if (j < 3) {
					if (checkWinner(board, '3', i, j, 'b')) bWin = TRUE;
					if (checkWinner(board, '3', i, j, 'w')) wWin = TRUE;
				}
				else {
					if (checkWinner(board, '4', i, j, 'b')) bWin = TRUE;
					if (checkWinner(board, '4', i, j, 'w')) wWin = TRUE;
				}
			}
		}
	}

	// check if board is full
	// it's possible that a user won while the board is full!
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == 0) { full = FALSE; break; }
		}
		if (full == FALSE) { break; }
	}

	if (bWin && wWin) {
		return 'B';//means BOTH WON!
	}
	else if (bWin) {
		return 'b';//means b WON!
	}
	else if (wWin) {
		return 'w'; //means w WON!
	}
	else if (full) {
		return 'F'; //means the game finished and no one won!
	}


	return 'N'; //means no one won yet...
}