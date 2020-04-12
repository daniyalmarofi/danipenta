#include "constants.h"

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

    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            // checking vertical
            if (i < 3 && j < 5){
                if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j] && board[i + 3][j] == board[i + 3][j + 1]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i<3 && j> 0){
                if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j] && board[i + 3][j] == board[i + 3][j - 1]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i > 2 && j < 5){
                if (board[i][j] == board[i - 1][j] && board[i - 1][j] == board[i - 2][j] && board[i - 2][j] == board[i - 3][j] && board[i - 3][j] == board[i - 3][j + 1]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i > 2 && j > 0){
                if (board[i][j] == board[i - 1][j] && board[i - 1][j] == board[i - 2][j] && board[i - 2][j] == board[i - 3][j] && board[i - 3][j] == board[i - 3][j - 1]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }

            // checking vertical
            if (i<5 && j> 2){
                if (board[i][j] == board[i][j - 1] && board[i][j - 1] == board[i][j - 2] && board[i][j - 2] == board[i][j - 3] && board[i][j - 3] == board[i + 1][j - 3]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i > 0 && j > 2){
                if (board[i][j] == board[i][j - 1] && board[i][j - 1] == board[i][j - 2] && board[i][j - 2] == board[i][j - 3] && board[i][j - 3] == board[i - 1][j - 3]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i < 5 && j < 2){
                if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j + 3] == board[i + 1][j + 3]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i > 0 && j < 2){
                if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j + 3] == board[i - 1][j + 3]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }

            // checking first diagonal
            if (i<2 && j> 2){
                if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 2][j - 2] == board[i + 3][j - 3] && board[i + 3][j - 3] == board[i + 4][j - 2]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i<3 && j> 3){
                if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 2][j - 2] == board[i + 3][j - 3] && board[i + 3][j - 3] == board[i + 2][j - 4]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i > 2 && j < 2){
                if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 2][j + 2] && board[i - 2][j + 2] == board[i - 3][j + 3] && board[i - 3][j + 3] == board[i - 2][j + 4]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i > 3 && j < 3){
                if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 2][j + 2] && board[i - 2][j + 2] == board[i - 3][j + 3] && board[i - 3][j + 3] == board[i - 4][j + 3]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            
            // checking second diagonal
            if (i < 3 && j < 2){
                if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 2][j + 4]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i < 2 && j < 3){
                if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 4][j + 2]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i > 3 && j > 2){
                if (board[i][j] == board[i - 1][j - 1] && board[i - 1][j - 1] == board[i - 2][j - 2] && board[i - 2][j - 2] == board[i - 3][j - 3] && board[i - 3][j - 3] == board[i - 4][j - 2]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
                }
            }
            if (i > 2 && j > 3){
                if (board[i][j] == board[i - 1][j - 1] && board[i - 1][j - 1] == board[i - 2][j - 2] && board[i - 2][j - 2] == board[i - 3][j - 3] && board[i - 3][j - 3] == board[i - 2][j - 4]){
                    if (board[i][j] == 'w')
                        wWin = TRUE;
                    else if (board[i][j] == 'b')
                        bWin = TRUE;
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