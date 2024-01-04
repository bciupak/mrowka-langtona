
#include "genBoard.h"
#include "ant.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "characters.h"




int randrange(int a, int b) {

    int randomNum = rand() % b + a;

    return randomNum;
}
void boardOut(wchar_t **board, int n, int m){

    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < m + 1; j++)
            printf("%lc", board[i][j]);
        
        printf("\n");
    }


}

int binarySearch(wchar_t *board, int low, int high, wchar_t target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (board[mid] == target)
            return mid;  

        if (board[mid] < target)
            low = mid + 1; 

        else
            high = mid - 1;  
    }

    return -1;
}

void korekta(wchar_t ** board, int blackCounter, int n, int m){

    // int checkI = randrange(1, n -2);
    int i = 0;
    int result;
    int check = 0;
    while (blackCounter > 0){

        result = binarySearch(board[i], 1, m - 1, SQUARE_WHITE[0]);
        if (result != -1){
            board[i][result] = SQUARE_BLACK[0];
            blackCounter -= 1;
            
        } else
            i += 1;
        
        }


          
       
}



void freeBoard(wchar_t** board, int rows) {
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
}

wchar_t** genMap(int n, int m, int percent, int antX, int antY, char* direction) {
    srand(time(NULL));

    int dir = DirectionNumber(direction);

    n += 1;
    m += 1;

    float blackChance = percent;
    int blackCount = round(((n - 2) * (m - 2)) * (blackChance/100));


    wchar_t **board = (wchar_t**)malloc(n * sizeof(wchar_t*));
 
    for (int i = 0; i <= n; i++) {
        board[i] = (wchar_t*)malloc(m * sizeof(wchar_t));

        for (int j = 0; j < m; j++) {
            if (i == 0){
                if (j == 0)
                    board[i][j] = LINE_DOWN_RIGHT[0];
                else if (j == m - 1)
                    board[i][j] = LINE_DOWN_LEFT[0];
                else 
                    board[i][j] = LINE_HORIZONTAL[0];
            }
            else if (i == n - 1){
                if (j == 0)
                    board[i][j] = LINE_UP_RIGHT[0];
                else if (j == m - 1)
                    board[i][j] = LINE_UP_LEFT[0];
                else
                    board[i][j] = LINE_HORIZONTAL[0];

            }

            else if (j == 0 || j == m - 1){
                board[i][j] = LINE_VERTICAL[0];
            }

            else{
                if (randrange(1, 100) <= blackChance && blackCount > 0){
                    board[i][j] = SQUARE_BLACK[0];
                    blackCount -= 1;

                }
                    
                else{
                    board[i][j] = SQUARE_WHITE[0];  
                }          
                
            }
            
        }
        
        
    }
    
    korekta(board,blackCount,n, m);


    board[antX][antY]  = dictAnt(dir, Color(board[antX][antY]));


    return board;

    
}

