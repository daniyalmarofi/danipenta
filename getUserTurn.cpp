#include "graphics.h"
#include "drawBoard.h"

void showPointer(int i, int j) {
	setcolor(BLUE);
	setlinestyle(SOLID_LINE, 0xFFFF, 7);
	rectangle(getCoordinate(i, j, 'i') - 4, getCoordinate(i, j, 'j') - 4, getCoordinate(i, j, 'i') + 4, getCoordinate(i, j, 'j') + 4);

	return;
}

void clearPointer(char board[][6], int i, int j) {
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

void movePointer(int i,int j, char operation) {
	if (operation == 'w') {
		showPointer(i, j - 1);
	}
	else if (operation == 's') {
		showPointer(i, j + 1);
	}
	else if (operation == 'd') {
		showPointer(i + 1, j);
	}
	else if (operation == 'a') {
		showPointer(i - 1, j);
	}
	return;
}

int checkInput(int i, int j) {
	if (i < 0 || i >= 6 || j<0 || j >= 6)
		return 0;
	return 1;
}

void getUserTurn(char board[][6],char turn) {
	int i = 0, j = 0;
	showPointer(0, 0);
	while (1) {
		while (!kbhit)
		{
			delay(100);
		}

		printf(":");

		
			char ch = getch();
			printf("%c", ch);
			if (ch == 'w') {
				if (checkInput(i, j - 1) == 0) {
					printf("\nWrong input! Try again! :");
					continue;
				}
				movePointer(i, j, 'w');
				clearPointer(board, i, j);
				j--;
			}
			else if (ch == 's') {
				if (checkInput(i, j + 1) == 0) {
					printf("\nWrong input! Try again! :");
					continue;
				}
				movePointer(i, j, 's');
				clearPointer(board, i, j);
				j++;
			}
			else if (ch == 'a') {
				if (checkInput(i-1, j) == 0) {
					printf("\nWrong input! Try again! :");
					continue;
				}
				movePointer(i, j, 'a');
				clearPointer(board, i, j);
				i--;
			}
			else if (ch == 'd') {
				if (checkInput(i+1, j) == 0) {
					printf("\nWrong input! Try again! :");
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
					printf("This place is already taken! Try another! :");
					continue;
				}
			}
		}
	
}