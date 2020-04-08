
void showBoard() {
	system("cls");
	printf("  \t1\t2\t3\t \t4\t5\t6 \n");
	printf("  ______________________________________________________________ \n |\t \t \t \t|\t \t \t \t|\n");
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (i == 3) { printf(" |\t \t \t \t|\t \t \t \t|\n |------------------------------|-------------------------------|\n |\t \t \t \t|\t \t \t \t|\n"); }
		else if (i > 0) { printf(" |\t \t \t \t|\t \t \t \t|\n |\t \t \t \t|\t \t \t \t|\n |\t \t \t \t|\t \t \t \t|\n"); }
		printf("%d|", (i + 1));
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (j == 3) { printf("\t|"); }
			if (board[i][j] == 0) { printf("\t."); }
			else { printf("\t%c", board[i][j]); }
			if (j == 5) { printf("\t|\n"); }
		}
	}
	printf(" |\t \t \t \t|\t \t \t \t|\n |______________________________|_______________________________|\n");
}