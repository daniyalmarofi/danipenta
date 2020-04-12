#ifndef BOARD_SIZE
#include "graphics.h"
#include "drawBoard.h"
#include "constants.h"
#endif

// ** This functions shows the pointer in point (i,j) of the board
void showPointer(int i, int j) {
	setcolor(BLUE);
	setlinestyle(SOLID_LINE, 0xFFFF, 7);
	rectangle(getCoordinate(i, j, 'i') - 4, getCoordinate(i, j, 'j') - 4, getCoordinate(i, j, 'i') + 4, getCoordinate(i, j, 'j') + 4);
	return;
}

// ** This function clears the pointer from the point (i,j) of the board
void clearPointer(char board[][BOARD_SIZE], int i, int j) {
	char fillColor;
	if (board[j][i] == 'w')
		fillColor = WHITE;
	else if (board[j][i] == 'b')
		fillColor = BLACK;
	else
		fillColor = RED;
	setfillstyle(SOLID_FILL, fillColor);
	floodfill(getCoordinate(i, j, 'i'), getCoordinate(i, j, 'j'), YELLOW);
}

// ** this function shows the next pointer in the board acoording to previous point
void movePointer(int i,int j, char operation) {
	if (operation == 'w')
		showPointer(i, j - 1);
	else if (operation == 's')
		showPointer(i, j + 1);
	else if (operation == 'd')
		showPointer(i + 1, j);
	else if (operation == 'a')
		showPointer(i - 1, j);
	return;
}

// ** This function check if user selected the correct point or not returns 1 if OK
int checkInput(int i, int j) {
	if (i < 0 || i >= BOARD_SIZE || j < 0 || j >= BOARD_SIZE)
		return FALSE;
	return TRUE;
}

// ** this function shows the direction with chosen direction
void drawDirection(int x, int y, char direction, int color) {
	setcolor(color);
	setlinestyle(SOLID_LINE, 0xFFFF, 9);
	if (direction == '-') {
		arc(x, y, 270, 90, 60);
		line(x, y - 60 - 15, x - 16, y - 60);
		line(x, y - 60 + 15, x - 16, y - 60);
	}
	else if (direction == '+') {
		arc(x, y, 90, 270, 60);
		line(x, y - 60 - 15, x + 16, y - 60);
		line(x, y - 60 + 15, x + 16, y - 60);
	}

}

// ** this function gets the directions from user for the selected area
char getDirection(int area) {
	// printf("\nselect the direction of rotate:");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
	setcolor(LIGHTBLUE);
	outtextxy(520, 220, "choose the direction to rotate");
	outtextxy(520, 250, "use -/+ to select direction   ");
	outtextxy(520, 300, "                              ");
	outtextxy(520, 320, "                              ");

    // defining the coordiantes of arrows in each area
	char direction=0;
	int x1Center, y1Center, x2Center, y2Center;
	if (area == 1) {
		x1Center = 375;
		x2Center = 375;
		y1Center = 130;
		y2Center = 190;
	}
	else if (area == 2) {
		x1Center = 160;
		x2Center = 160;
		y1Center = 190;
		y2Center = 130;
	}
	else if(area == 3) {
		x1Center = 160;
		x2Center = 160;
		y1Center = 345;
		y2Center = 405;
	}
	else if(area == 4) {
		x1Center = 375;
		x2Center = 375;
		y1Center = 345;
		y2Center = 405;
	}

	drawDirection(x1Center, y1Center, '+', CYAN);
	drawDirection(x2Center, y2Center, '-', LIGHTMAGENTA);

    // getting user input
	while (TRUE) {

        // waiting for keyboad
		while (!kbhit) {
			delay(100);
		}

		//get user input for direction of rotation
		char ch = getch();
		if (ch == '+') {
			drawDirection(x1Center, y1Center, '+', GREEN);
			drawDirection(x2Center, y2Center, '-', LIGHTMAGENTA);
			direction = '+';
		} else if (ch == '-') {
			drawDirection(x2Center, y2Center, '-', GREEN);
			drawDirection(x1Center, y1Center, '+', CYAN);
			direction = '-';
		}
		else if (ch == 'f') {
			if (direction == 0) {
				// printf("\nNo selected direction! Try again! :");
				settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
				setcolor(LIGHTRED);
				outtextxy(520, 300, "No selected direction!        ");
				outtextxy(520, 320, "Try again!                    ");
				continue;
			}
			break;
		}
		else {
			// printf("\nWrong input! Try again! :");
			settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
			setcolor(LIGHTRED);
			outtextxy(520, 300, "Wrong input! Try again!       ");
			continue;
		}
	}

	return direction;
}

// ** this function shows the pointer and asks users to select a point
void getUserTurn(char board[][BOARD_SIZE], char turn) {
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
	setcolor(LIGHTBLUE);
	outtextxy(520, 220, (turn == 'b' ? "BLACK player's turn:              " : "WHITE player's turn:              "));
	outtextxy(520, 250, "use w, a, s, d to move pointer");
	outtextxy(520, 275, "press f to confirm");
	outtextxy(520, 300, "                              ");
	outtextxy(520, 320, "                              ");
	// printf("\n%c player's turn:", turn);

    // initiate the first location of the pointer
	int i = 0, j = 0;
	showPointer(i, j);

    // geting user input
	while (TRUE) {
	
		//wait for input
		while (!kbhit)
		{
			delay(100);
		}

		//get the location of the point in the board
		char ch = getch();
		if (ch == 'w') {
			if (checkInput(i, j - 1) == 0) {
				// printf("\nWrong input! Try again! :");
				settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
				setcolor(LIGHTRED);
				outtextxy(520, 300, "Wrong input! Try again!       ");
				continue;
			}
			movePointer(i, j, 'w');
			clearPointer(board, i, j);
			j--;
		}
		else if (ch == 's') {
			if (checkInput(i, j + 1) == 0) {
				// printf("\nWrong input! Try again! :");
				settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
				setcolor(LIGHTRED);
				outtextxy(520, 300, "Wrong input! Try again!       ");
				continue;
			}
			movePointer(i, j, 's');
			clearPointer(board, i, j);
			j++;
		}
		else if (ch == 'a') {
			if (checkInput(i-1, j) == 0) {
				// printf("\nWrong input! Try again! :");
				settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
				setcolor(LIGHTRED);
				outtextxy(520, 300, "Wrong input! Try again!       ");
				continue;
			}
			movePointer(i, j, 'a');
			clearPointer(board, i, j);
			i--;
		}
		else if (ch == 'd') {
			if (checkInput(i+1, j) == 0) {
				// printf("\nWrong input! Try again! :");
				settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
				setcolor(LIGHTRED);
				outtextxy(520, 300, "Wrong input! Try again!       ");
				continue;
			}
			movePointer(i, j, 'd');
			clearPointer(board, i, j);
			i++;
		}
		else if (ch == 'f') {
			if (board[j][i] == 0) {
				board[j][i] = turn;
				break;
			}
			else {
				// printf("\nThis place is already taken! Try another! :");
				settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
				setcolor(LIGHTRED);
				outtextxy(520, 300, "This place is already taken!  ");
				outtextxy(520, 320, "Try another!                  ");
			}
		}
		else {
			// printf("\nWrong input! Try again! :");
			settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
			setcolor(LIGHTRED);
			outtextxy(520, 300, "Wrong input! Try again!       ");
		}
	}	

	return;
}