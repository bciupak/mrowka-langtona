#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include "characters.h"

#include "ant.h"
#include "genBoard.h"
#include "dataMgmt.h"

void test(int *n, int *m, int *i, int *percent, char **name, char **direction, char **in){
    *n = 10;
    *m = 10;
    *i = 1000;
    *percent = 25;
    *name = "mapaTest";
    // *direction = "s";
    *in = "mapaTest";

}

int main(int argc, char **argv) {
    // setting Unicode to UTF-8, so characters can show up
    setlocale(LC_ALL, "C.UTF-8");  


    int n, m, i, percent;
    char *name, *direction, *in;

    // testowanie

    test(&n, &m, &i, &percent, &name, &direction, &in );

    int x = round((n)/2);
    int y = round((m)/2);

    direction = argc > 2 ? argv[2] : "s";
    // printf("%s", direction);
    wchar_t** mapa;
    if (argc > 1){
        percent = atoi(argv[1]);
        mapa = genMap(n, m, percent, x, y, direction);
        boardOut(mapa, n, m);
        master(mapa, n, m, x, y, i, direction);
        fileOut(mapa, n, m, name);
   
    } else {
        mapa = fileIn(in, n, m);
        boardOut(mapa, n, m);
        master(mapa, n, m, x, y, i, direction);

        

    }

    
    

    return 0;
    }