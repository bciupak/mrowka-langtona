#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <math.h>

#include "genBoard.h"
#include "dataMgmt.h"

void test(int *n, int *m, int *i, int *percent, char **name, char **direction, char **map, char **in){
    *n = 30;
    *m = 20;
    *i = 10;
    *percent = 0;
    *name = "test0";
    *direction = "east";
    *map = "asf";

}

int main(int argc, char **argv) {
    // setting Unicode to UTF-8, so characters can show up
    setlocale(LC_ALL, "C.UTF-8");  


    int n, m, i, percent;
    char *name, *direction, *map, *in;

    test(&n, &m, &i, &percent, &name, &direction, &map , &in );

    wchar_t** mapa = genMap(n, m, percent);
    //mapa = fileIn();

    boardOut(mapa, n, m);

    fileOut(mapa, n, m, name);


    return 0;
    }
