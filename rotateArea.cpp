void rotateArea(char board[][6], int area, char dircetion) {
	
	int iFirst, jFirst;
	if (area == 1) {
		iFirst = 0;
		jFirst = 3;
	}
	else if (area == 2) {
		iFirst = 0;
		jFirst = 0;
	}
	else if (area == 3) {
		iFirst = 3;
		jFirst = 0;
	}
	else if (area == 4) {
		iFirst = 3;
		jFirst = 3;
	}

	char temp[3][3] = { 0 };

	//rotate the selected area
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// +
			if (dircetion == '+') {
				temp[j][2 - i] = board[iFirst + i][jFirst + j];
			}
			else if (dircetion == '-') {
				temp[2 - j][i] = board[iFirst + i][jFirst + j];
			}
		}
	}

	//copy temp to board
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[iFirst + i][jFirst + j] = temp[i][j];
		}
	}
}