#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

void argError(char argName, char* value){

    char pValue = *value;

    
    if (pValue == '-'){
        fprintf(stderr, "Opcja -%c wymaga podania argumentu.\n", argName);
        exit(0);
    }

}

void intCheck(char argName, char* value){

    int i = 0;

    while (value[i] != '\0') {
        if (!isdigit(value[i])){
            fprintf(stderr, "Opcja -%c wymaga podania liczby.\n", argName);
            exit(0);
        }

        i++;
    }
        
}


void argumenty(int argc, char **argv, int* m, int* n, int* i, char** f, char** d, char** p, int* g){

    // -m (int) wiersze
    // -n (int) kolumny
    // -i (int) iteracje
    // -f (char*) nazwa plikow wyjsciowych
    // -d (char*) kierunek poczatkowy mrowki
    // -p (char*) mapa pokryta czarnymi (opcjonalnie)
    // -g (int) wygenerowanie nowej mapy zapelnionej procentowo czarnymi (opcjonalnie)

    // extern char *optarg;
    // extern int optind, optopt;
    int c;

    int argCheck = 0;
    int optArgCheck = 0;
    
    


    while ((c = getopt (argc, argv, "m:n:i:f:d:p:g:")) != -1)
        switch (c)
        {
        case 'm':

            argError(c, optarg);
            intCheck(c,optarg);
            *m = atoi(optarg);
            argCheck++;
            break;
        case 'n':
            argError(c, optarg);
            intCheck(c,optarg);
            *n = atoi(optarg);
            argCheck++;
            break;
        case 'i':
            argError(c, optarg);
            intCheck(c,optarg);
            *i = atoi(optarg);
            argCheck++;
            break;
        case 'f':
            argError(c, optarg);
            *f = optarg;
            argCheck++;
            break;
        case 'd':
            argError(c, optarg);
            
            if (strcmp(optarg, "w") && strcmp(optarg, "e") && strcmp(optarg, "n") && strcmp(optarg, "s")){
                fprintf (stderr, "Opcja -%c: Nie rozpoznano kierunku. Wybierz kierunek z podanych: {n, s, e, w}.\n", c);
                exit(0);
            }
            *d = optarg;
            argCheck++;
            break;
        case 'p':
            argError(c, optarg);
            *p = optarg;
            optArgCheck++;
            break;
        case 'g':    
            argError(c, optarg);
            intCheck(c,optarg);        
            *g = atoi(optarg);
            optArgCheck++;
            break;
        case '?':
            if (optopt == 'm' || optopt == 'n' || optopt == 'i' || optopt == 'd' || optopt == 'f' || optopt == 'p' || optopt == 'g'){
                fprintf (stderr, "Opcja -%c wymaga podania argumentu.\n", optopt);
            
            } else if (isprint (optopt)) {
                fprintf (stderr, "Opcja nieznana `-%c'.\n", optopt);
            }
            exit(0);
        default:
            abort();
        }

    if (argCheck < 5){
        fprintf(stderr, "Za malo podanych argumentow. Upewnij sie ze podales argumenty: m, n, i, f, d\n");
        exit(0);
    } else if (argCheck > 5){
        fprintf(stderr, "Za duzo podanych argumentow.\n");
        exit(0);
    }

    if (optArgCheck < 1){
        fprintf(stderr, "Za malo podanych argumentow: Musisz podac przynajmniej jeden z tych argumentow: g, p\n");
        exit(0);
    } else if (optArgCheck > 1) {
        fprintf(stderr, "Za duzo podanych argumentow: Argumentow g i p nie mozna uzywac na raz\n");
        exit(0);
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
    wchar_t **board = (wchar_t**)malloc((m + 1) * sizeof(wchar_t*));

     for (int i = 0; i <= m; i++) {
        board[i] = (wchar_t*)malloc((n + 2) * sizeof(wchar_t));
        for (int j = 0; j <= n + 1; j ++){
            buff = fgetwc(in);
            board[i][j] = buff;     
        }
        
     }
    

    return board;
}