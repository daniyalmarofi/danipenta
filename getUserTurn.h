#ifndef BOARD_SIZE
#include "constants.h"
#endif
void showPointer(int i, int j);
void movePointer(int i, int j, char operation);
void getUserTurn(char board[][BOARD_SIZE], char turn);
void clearPointer(char board[][BOARD_SIZE], int i, int j);
int checkInput(int i, int j);
char getDirection(int area);