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

void highlightArea(int area, int color) {
	int top, left, bottom, right;
	if (area == 1) {
		left = 265;
		right = 480;
		top = 50;
		bottom = 265;
	}
	else if(area == 2) {
		left = 50;
		right = 265;
		top = 50;
		bottom = 265;
	}
	else if(area == 3) {
		left = 50;
		right = 265;
		top = 265;
		bottom = 480;
	}
	else if(area == 4) {
		left = 265;
		right = 480;
		top = 265;
		bottom = 480;
	}

	setcolor(color);
	setlinestyle(SOLID_LINE, 0xFFFF, (color == BLUE ? 7 : 4));
	rectangle(left, top, right, bottom);
	return;
}

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

char getDirection(int area) {
	printf("\nselect the direction of rotate:");
	char direction;
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

	while (1) {

		while (!kbhit) {
			delay(100);
		}

		//get user input for direction of rotation
		printf(",:");
		char ch = getch();
		printf("%c", ch);
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
			break;
		}
	}

	return direction;
}

int getArea() {
	printf("getarea");
	int area = 1;
	highlightArea(area, BLUE);

	while (1) {

		while (!kbhit) {
			delay(100);
		}

		//get user input for selecting area
		printf("/:");
		char ch = getch();
		printf("%c", ch);
		if (ch == 'n') {
			highlightArea(area, YELLOW);
			area++;
			if (area == 5) {
				area = 1;
			}
			highlightArea(area,BLUE);
		}
		else if (ch == 'f') {
			break;
		}
	}
	return area;
}

void getUserTurn(char board[][6],char turn) {
	printf("\n%c player's turn:", turn);
	int i = 0, j = 0;
	showPointer(i, j);

	while (1) {
	
		//wait for input...
		while (!kbhit)
		{
			delay(100);
		}

		//get input
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
				printf("\nThis place is already taken! Try another! :");
				continue;
			}
		}
	}	

	return;
}