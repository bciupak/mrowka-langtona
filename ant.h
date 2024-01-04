#ifndef ANT
#define ANT

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "characters.h"



wchar_t dictAnt (int direction, char* color);

char* Color(wchar_t square);

wchar_t changeColor(char* color);


int DirectionNumber (char* direction);

void master(wchar_t** board,int n, int m, int x, int y, int iteration, char* startDirection);

#endif //ANT