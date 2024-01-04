#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

char* filename_Number(char* name, int number) {
    const char* dirPrefix = "output_files/";

    int nameLen = strlen(name);
    int numLen = snprintf(NULL, 0, "_%d", number);

    char* file = (char*)malloc(nameLen + numLen + 2 + strlen(dirPrefix));

    if (file == NULL) 
        return NULL;

    strcpy(file, dirPrefix);
    strcat(file, name);
    snprintf(file + nameLen + strlen(dirPrefix), numLen + 2, "_%d", number);




    return file;
}


void fileOut(wchar_t** board, int n, int m, char* name){

    

    FILE *out = fopen(name, "w");

    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < m + 1; j++)
            fprintf(out,"%lc", board[i][j]);
        fprintf(out, "\n");
    }

    fclose(out);

}


wchar_t** fileIn(char* name,int n, int m){
    FILE* in = fopen(name, "r");
    wint_t buff;
    wchar_t **board = (wchar_t**)malloc((n) * sizeof(wchar_t*));

     for (int i = 0; i <= n; i++) {
        board[i] = (wchar_t*)malloc((m + 1) * sizeof(wchar_t));
        for (int j = 0; j <= m + 1; j ++){
            buff = fgetwc(in);
            board[i][j] = buff;     
        }
        
     }
    

    return board;
}