#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>


void fileOut(wchar_t** board, int n, int m, char* name){

    FILE *out = fopen(name, "w");

    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < m + 1; j++)
            fprintf(out,"%lc", board[i][j]);
        fprintf(out, "\n");
    }

}


wchar_t fileIn(){






}