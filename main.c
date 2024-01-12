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

void test(int *m, int *n, int *i, int *percent, char **name, char **direction, char **in){
    *m = 10;
    *n = 10;
    *i = 1000;
    *percent = 25;
    *name = "mapaTest";
    *direction = "s";
    *in = "mapaTest";

}

int main(int argc, char **argv) {
    // setting Unicode to UTF-8, so characters can show up
    setlocale(LC_ALL, "C.UTF-8");  


    int m, n, i, g = 0;
    char *f = NULL, *d, *in, *p = NULL;
    
    argumenty(argc, argv, &m, &n, &i, &f, &d, &p, &g);

    
    // test(&m, &n, &i, &g, &f, &d, &in );

    int x = round((m)/2);
    int y = round((n)/2);

 
    wchar_t** mapa;
    m += 1;
    n += 1;

    if (p == NULL){
        // procent i kierunek

        printf("Wygenerowana mapa:\n\n");
        mapa = genMap(m, n, g, x, y, d);
        boardOut(mapa, m, n);
        fileOut(mapa, m, n, f);
    
       
        master(mapa, m, n, x, y, i, d, f);


    } else {
    // preset
        printf("Wczytana mapa:\n\n");

        mapa = fileIn(p, m, n);

        boardOut(mapa, m, n);
        arrowSearch(mapa, m, n, &x, &y);
        master(mapa, m, n, x, y, i, d, f);
    }
        

    

    printf("Koniec symulacji. Wykonano %d iteracji\n", i);
    

    return 0;
    }