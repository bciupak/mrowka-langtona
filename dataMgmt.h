#ifndef DATA
#define DATA

void argError(char argName,char* value);

void intCheck(char argName, char* value);

void argumenty(int argc, char **argv, int* m, int* n, int* i, char** f, char** d, char** p, int* g);

char* filename_Number(char* name, int number);

wchar_t** fileIn(char* name,int n, int m);

void fileOut(wchar_t** board, int n, int m, char* name);

#endif //DATA