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


int main(int argc, char **argv) {
    setlocale(LC_ALL, "C.UTF-8");  


    int m, n, i, g = 0;
    char *f = NULL, *d, *in, *p = NULL;
    
    argumenty(argc, argv, &m, &n, &i, &f, &d, &p, &g);

    
    int x = round((m)/2);
    int y = round((n)/2);

 
    wchar_t** mapa;
    m += 1;
    n += 1;

    if (p == NULL){
        // procent i kierunek

        printf("Wygenerowana mapa:\n\n");
        mapa = genMap(m, n, g, x, y, d);
        
        
        if (f != NULL){
            boardOut(mapa, m, n);
            fileOut(mapa, m, n, f);
        }
        master(mapa, m, n, x, y, i, d, f);


    } else {
    // preset
        printf("Wczytana mapa:\n\n");

        mapa = fileIn(p, m, n);
        if (f != NULL)
            boardOut(mapa, m, n);
        arrowSearch(mapa, m, n, &x, &y);
        master(mapa, m, n, x, y, i, d, f);
    }
        

    

    printf("Koniec symulacji. Wykonano %d iteracji\n", i);
    

    return 0;
    }
