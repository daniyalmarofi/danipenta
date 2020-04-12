#ifndef BOARD_SIZE
#include "graphics.h"
#include "constants.h"
#endif

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
	char direction = 0;
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
	else if (area == 3) {
		x1Center = 160;
		x2Center = 160;
		y1Center = 345;
		y2Center = 405;
	}
	else if (area == 4) {
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
		}
		else if (ch == '-') {
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