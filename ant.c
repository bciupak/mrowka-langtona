#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>

#include "dataMgmt.h"
#include "characters.h"
#include "ant.h"
#include "genBoard.h"

// W - west
// E - east
// N - north
// S - south




wchar_t dictAnt(int direction, char* color) {
    wchar_t result;

    switch (direction) {
        case 3: // WEST
            if (strcmp(color, "black") == 0)
                result = ARROW_WEST_BLACK[0];
            else if (strcmp(color, "white") == 0)
                result = ARROW_WEST_WHITE[0];
            break;

        case 1: // EAST
            if (strcmp(color, "black") == 0)
                result = ARROW_EAST_BLACK[0];
            else if (strcmp(color, "white") == 0)
                result = ARROW_EAST_WHITE[0];
            break;

        case 0: // NORTH
            if (strcmp(color, "black") == 0)
                result = ARROW_NORTH_BLACK[0];
            else if (strcmp(color, "white") == 0)
                result = ARROW_NORTH_WHITE[0];
            break;

        case 2: // SOUTH
            if (strcmp(color, "black") == 0)
                result = ARROW_SOUTH_BLACK[0];
            else if (strcmp(color, "white") == 0)
                result = ARROW_SOUTH_WHITE[0];
            break;

        default:
            printf("\nBledzik totalny\n");
            break;
    }

    return result;
}

char* Color(wchar_t square){
    if (square == SQUARE_BLACK[0])
        return "black";
    else
        return "white";
} 

wchar_t changeColor(char* color){
    if (strcmp(color, "white") == 0)
        return SQUARE_BLACK[0];
    else
        return SQUARE_WHITE[0];
        
} 


int DirectionNumber (char* direction){
    if (strcmp(direction, "n") == 0)
        return 0;
    else if (strcmp(direction, "e") == 0)
        return 1;
    else if (strcmp(direction, "s") == 0)
        return 2;
    else if (strcmp(direction, "w") == 0)
        return 3;
}

void master(wchar_t** board,int n, int m, int x, int y, int iteration, char* startDirection){

    int k = DirectionNumber(startDirection);

    char* color;

    

    if (board[x][y] == ARROW_EAST_BLACK[0] || board[x][y] == ARROW_WEST_BLACK[0] || board[x][y] == ARROW_NORTH_BLACK[0] || board[x][y] == ARROW_SOUTH_BLACK[0])
        color = "black";
    else
        color = "white";
    

    
    for (int i = 0; i < iteration; i ++){

        if (strcmp(color, "white") == 0){
            k += 1;
            if (k > 3)
                k = 0;
        }
        else if (strcmp(color, "black") == 0){
            k -= 1;
            if (k < 0)
                k = 3;  
        }

        switch (k){
            case 0: // NORTH
                board[x][y] = changeColor(color);
                x -= 1;
                break;
            case 1: // EAST
                board[x][y] = changeColor(color);
                y += 1;
                break;
            case 2: // SOUTH
                board[x][y] = changeColor(color);
                x += 1;
                break;
            case 3: // WEST
                board[x][y] = changeColor(color);
                y -= 1;
                break;

        }

        if (x <= 0 || x >= n || y <= 0 || y >= m){
            printf("\n\nkoniec programu\n\n");
            exit(0);
        }
        color = Color(board[x][y]);
        board[x][y] = dictAnt(k, Color(board[x][y]));


        char* name = filename_Number("file", i);

        fileOut(board, n, m, name);


        

    }


    
}


    



