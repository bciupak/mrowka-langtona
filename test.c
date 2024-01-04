#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filename_Number(char* name, int number) {
   
    int nameLen = strlen(name);
    int numLen = snprintf(NULL, 0, "_%d", number); 


    char *file = (char *)malloc(nameLen + numLen + 1); 

    
    strcpy(file, name);

    
    snprintf(file + nameLen, numLen + 1, "_%d", number);


    printf("Result: %s\n", file);

 
    free(file);

}

int main(){

    filename_Number("file", 1);
    
    return 0;
}