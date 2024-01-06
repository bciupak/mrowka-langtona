#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

void argumenty(int argc, char **argv, int* m, int* n, int* i, char** f, char** d, char** p, int* g){

    // -m (int) wiersze
    // -n (int) kolumny
    // -i (int) iteracje
    // -f (char*) nazwa plików wyjsciowych (opcojnalnie)
    // -d (char*) kierunek poczatkowy mrowki
    // -p (char*) mapa pokryta czarnymi (opcjonalnie)
    // -g (int) wygenerowanie nowej mapy zapelnionej procentowo czarnymi (opcjonalnie)

    extern char *optarg;
    extern int optind, optopt;
    int c;



    // if (argc != 5){
    //     fprintf (stderr, "Za malo argumentow\n");
    //     exit(0);
    // }
    while ((c = getopt (argc, argv, "m:n:i:f:d:p:g:")) != -1)
        switch (c)
        {
        case 'm':
            *m = atoi(optarg);
            break;
        case 'n':
            *n = atoi(optarg);
            break;
        case 'i':
            *i = atoi(optarg);
            break;
        case 'f':
            *f = optarg;
            break;
        case 'd':
            *d = optarg;
            break;
        case 'p':
            break;
        case 'g':            
            *g = atoi(optarg);
            break;
        case '?':
            if (optopt == 'm' || optopt == 'n' || optopt == 'i' || optopt == 'd' || optopt == 'f' || optopt == 'p' || optopt == 'g')
            fprintf (stderr, "Opcja -%c wymaga podania argumentu.\n", optopt);
            else if (isprint (optopt))
            fprintf (stderr, "Opcja nieznana `-%c'.\n", optopt);
            exit(0);
        default:
            abort ();
        }



}


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


void fileOut(wchar_t** board, int m, int n, char* name){

    

    FILE *out = fopen(name, "w");

    for (int i = 0; i < m + 1; i++){
        for (int j = 0; j < n + 1; j++)
            fprintf(out,"%lc", board[i][j]);
        fprintf(out, "\n");
    }

    fclose(out);

}


wchar_t** fileIn(char* name,int m, int n){
    FILE* in = fopen(name, "r");
    wint_t buff;
    wchar_t **board = (wchar_t**)malloc((m) * sizeof(wchar_t*));

     for (int i = 0; i <= m; i++) {
        board[i] = (wchar_t*)malloc((n + 1) * sizeof(wchar_t));
        for (int j = 0; j <= n + 1; j ++){
            buff = fgetwc(in);
            board[i][j] = buff;     
        }
        
     }
    

    return board;
}
