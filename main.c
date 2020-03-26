#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void showBoard();
void getUserInput(char );
void rotateArea(int , char);
char checkGame();
int checkWinner(char,int,int,char);

char board[6][6]={0};


int main(){
    char gameResult;

    while (TRUE){
        showBoard();
        gameResult=checkGame();
        if (gameResult!='N') break;
        getUserInput('b');
        showBoard();
        gameResult=checkGame();
        if (gameResult!='N') break;
        getUserInput('w');
    }

    if(gameResult=='F'){
        printf("NO ONE WON!");
    }else{
        printf("THE PLAYER %c WON!",gameResult);
    }
    
    getchar();
    return 0;
}

int checkWinner(char action, int row,int col, char turn){
    // action::
    // v = top down check
    // V = bottom up check
    // h = left right check
    // H = right left check
    // 1 = first diaginal check
    // 2 = second diagonal check
    // 3 = third diagonal check
    // 4 = forth diagonal check
    int i;
    for (i = 0; i < 4; i++){
        switch (action){
            case 'v':
            if(board[row+i][col]!=turn) return FALSE;
            break;
            case 'V':
            if(board[row-i][col]!=turn) return FALSE;
            break;
            case 'h':
            if(board[row][col+i]!=turn) return FALSE;
            break;
            case 'H':
            if(board[row][col-i]!=turn) return FALSE;
            break;
            case '1':
            if(board[row+i][col+i]!=turn) return FALSE;
            break;
            case '2':
            if(board[row+i][col-i]!=turn) return FALSE;
            break;
            case '3':
            if(board[row-i][col+i]!=turn) return FALSE;
            break;
            case '4':
            if(board[row-i][col-i]!=turn) return FALSE;
            break;
        }
    }
    int row1,col1,row2,col2;

    switch (action){
        case 'v':
        row1=3;col1=1;
        row2=3;col2=-1;
        break;
        case 'V':
        row1=-3;col1=1;
        row2=-3;col2=-1;
        break;
        case 'h':
        row1=1;col1=3;
        row2=-1;col2=3;
        break;
        case 'H':
        row1=1;col1=-3;
        row2=-1;col2=-3;
        break;
        case '1':
        row1=4;col1=2;
        row2=2;col2=4;
        break;
        case '2':
        row1=4;col1=-2;
        row2=2;col2=-4;
        break;
        case '3':
        row1=-4;col1=2;
        row2=-2;col2=4;
        break;
        case '4':
        row1=-2;col1=-4;
        row2=-4;col2=-2;
        break;
    }

    if(board[row+row1][col+col1]==turn || board[row+row2][col+col2]==turn){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

char checkGame(){

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){

            if(j<3){
                if(checkWinner('h',i,j,'b')) return 'b';
                if(checkWinner('h',i,j,'w')) return 'w';
            }else{
                if(checkWinner('H',i,j,'b')) return 'b';
                if(checkWinner('H',i,j,'w')) return 'w';
            }

            if(i<3){
                if(checkWinner('v',i,j,'b')) return 'b';
                if(checkWinner('v',i,j,'w')) return 'w';

                if(j<3){
                    if(checkWinner('1',i,j,'b')) return 'b';
                    if(checkWinner('1',i,j,'w')) return 'w';
                }else{
                    if(checkWinner('2',i,j,'b')) return 'b';
                    if(checkWinner('2',i,j,'w')) return 'w';
                }
            }else{
                if(checkWinner('V',i,j,'b')) return 'b';
                if(checkWinner('V',i,j,'w')) return 'w';
                
                if(j<3){
                    if(checkWinner('3',i,j,'b')) return 'b';
                    if(checkWinner('3',i,j,'w')) return 'w';
                }else{
                    if(checkWinner('4',i,j,'b')) return 'b';
                    if(checkWinner('4',i,j,'w')) return 'w';
                }
            }
        }
    }
    
    // check if board is full
    // it's possible that a user won while the board is full!
    int full=TRUE;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if(board[i][j]==0){full=FALSE;break;}
        }
        if(full==FALSE){break;}
    }

    if (full==TRUE) return 'F'; //means the game finished and no one won!
    

    return 'N'; //means no one won yet...
}

void getUserInput(char turn){
    printf("\n%c player's turn:",turn);
    int input=0,y=0;
    int getOK=1;
    while(getOK){
        y=scanf("%d",&input);
        // ignore if user input was "abc..." : clearBuffer
        // TODO fix bug in 20fdfdfdsfgdfgrjhfgds
        while(getchar() != '\n');
        if(y!=1 || input<11){
            printf("Wrong input! Try again! :");
            continue;
            }
        getOK=0;
        int column=input%10;
        int row=input/10;
        if(column>6 || row>6 || column<1 || row<1){getOK=1;printf("Wrong input! Try again! :");continue;}
        if(board[row-1][column-1]==0){
            board[row-1][column-1]=turn;
        }else{
            getOK=1;printf("This place is already taken! Try another! :");
        }
    }
    printf("select the area to rotate:");
    int selectedArea=0;
    getOK=1;
    while(getOK){
        y=scanf("%d",&selectedArea);
        // ignore if user input was "abc..." : clearBuffer
        // TODO fix bug in 20fdfdfdsfgdfgrjhfgds
        while(getchar() != '\n');
        if(y!=1 || selectedArea<1 || selectedArea>4){
            printf("Wrong input! Try again! :");
            continue;
        }
        getOK=0;
    }

    printf("select the direction of rotate:");
    char direction;
    getOK=1;
    while (getOK)
    {
        y=scanf("%c",&direction);
        // ignore if user input was "abc..." : clearBuffer
        // TODO fix bug in 20fdfdfdsfgdfgrjhfgds
        while(getchar() != '\n');
        if(y!=1 || (direction!='-' && direction!='+')){
            printf("Wrong input! Try again! :");
            continue;
        }
        getOK=0;
    }
    // do the rotate
    rotateArea(selectedArea,direction);

}

void rotateArea(int area, char dircetion){
    int iFirst,jFirst;
    if(area==1){
        iFirst=0;
        jFirst=3;
    }else if(area==2){
        iFirst=0;
        jFirst=0;
    }else if(area==3){
        iFirst=3;
        jFirst=0;
    }else if(area==4){
        iFirst=3;
        jFirst=3;
    }
    char temp[3][3]={0};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            // +
            if(dircetion=='+'){
                temp[j][2-i]=board[iFirst+i][jFirst+j];
            }else if(dircetion=='-'){
                temp[2-j][i]=board[iFirst+i][jFirst+j];
            }
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            // if(temp[i][j]==0){printf("\t.");}
            // else{printf("\t%c",temp[i][j]);}
            board[iFirst+i][jFirst+j]=temp[i][j];
        }
    }
    

}

void showBoard(){
    system("cls");
    printf("  \t1\t2\t3\t \t4\t5\t6 \n");
    printf("  ______________________________________________________________ \n |\t \t \t \t|\t \t \t \t|\n");
    for (int i = 0; i < 6; i++)
    {
        if(i==3){printf(" |\t \t \t \t|\t \t \t \t|\n |------------------------------|-------------------------------|\n |\t \t \t \t|\t \t \t \t|\n");}
        else if(i>0){printf(" |\t \t \t \t|\t \t \t \t|\n |\t \t \t \t|\t \t \t \t|\n |\t \t \t \t|\t \t \t \t|\n");}
        printf("%d|",(i+1));
        for (int j = 0; j < 6; j++){
            if(j==3){printf("\t|");}
            if(board[i][j]==0){printf("\t.");}
            else{printf("\t%c",board[i][j]);}
            if(j==5){printf("\t|\n");}
        }
    }
    printf(" |\t \t \t \t|\t \t \t \t|\n |______________________________|_______________________________|\n");
}