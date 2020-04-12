#ifndef BOARD_SIZE
#include "constants.h"
#endif

void getUserInput(char board[][BOARD_SIZE], char turn);
void rotateArea(char board[][BOARD_SIZE], int area, char direction);