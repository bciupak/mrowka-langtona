#ifndef GENBOARD
#define GENBOARD

#include <stdio.h>
#include <wchar.h>

// losowy int z zasiegu <a, b>
int randrange(int a, int b);

// wypisywanie planszy
void boardOut(wchar_t **board, int rows, int columns);

// szukanie binarne
int binarySearch(wchar_t *board, int low, int high, wchar_t target);

// uzupelnianie miejsc ktorych nie zapelnila funkcja losowa
void korekta(wchar_t ** board, int blackCounter, int rows, int columns);

// usuniecie planszy ze sterty
void freeBoard(wchar_t** board, int rows);

// generowanie mapy
wchar_t** genMap(int n, int m, int percent,int antX, int antY, char* direction);

#endif //GENBOARD