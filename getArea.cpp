#ifndef BOARD_SIZE
#include "graphics.h"
#include "constants.h"
#endif

// ** this function puts a blue rectangle to select the area to rotate
void highlightArea(int area, int color) {
	int top, left, bottom, right;
	if (area == 1) {
		left = 265;
		right = 480;
		top = 50;
		bottom = 265;
	}
	else if (area == 2) {
		left = 50;
		right = 265;
		top = 50;
		bottom = 265;
	}
	else if (area == 3) {
		left = 50;
		right = 265;
		top = 265;
		bottom = 480;
	}
	else if (area == 4) {
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

// ** this function gets the area to rotate from user and returns the selected area
int getArea() {
	// printf("\ngetarea");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
	setcolor(LIGHTBLUE);
	outtextxy(520, 220, "choose a plate to rotate      ");
	outtextxy(520, 250, "use n to go to next plate     ");
	outtextxy(520, 300, "                              ");
	outtextxy(520, 320, "                              ");

	int area = 1;
	highlightArea(area, BLUE);

	// get user input
	while (TRUE) {

		// waiting for input
		while (!kbhit) {
			delay(100);
		}

		//get user input for selecting area
		char ch = getch();
		if (ch == 'n') {
			highlightArea(area, YELLOW);
			area++;
			if (area == 5) {
				area = 1;
			}
			highlightArea(area, BLUE);
		}
		else if (ch == 'f') {
			break;
		}
		else {
			// printf("\nWrong input! Try again! :");
			settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
			setcolor(LIGHTRED);
			outtextxy(520, 300, "Wrong input! Try again!       ");
		}
	}
	return area;
}