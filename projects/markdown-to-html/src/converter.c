#include "converter.h"
#include <stdio.h>
#include <stdlib.h>

const int findLen(char* filename){
    int c = 0;
    char ch;
    FILE* fileptr; 
    const char* mode = "r";
    fileptr = fopen(filename, mode);

    while ((ch = fgetc(fileptr)) != EOF){
        c++;
    }
    
    return c;
}


const int handleFileFunc(char* filename){
    FILE* fileptr; 
    int *lengthPtr;
    char string[100];
    const int fileLength = findLen(filename);
    lengthPtr = (char*) malloc(fileLength * sizeof(fileLength));

    if (lengthPtr == NULL)
    {
        printf("Error! Memory Not Allocated");
        return 1;
    }
    
    // char string[lengthPtr]; 
    const char* mode = "r";
    char ch;
    fileptr = fopen(filename, mode);

    if(fileptr == NULL){
        printf("Error! There is an issue with the file! Please try again!");
        return 1;
    }else {
        printf("The file has been successfully opened.");
    }

    while ((ch = fgetc(fileptr)) != EOF){
        fscanf(fileptr, "%[^\n]", string);
        printf("\n%s", string);
    }


    free(lengthPtr);
    fclose(fileptr);
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Please Enter One File As An Argument!");
        return 1;
    };

    handleFileFunc(argv[1]);
    return 0;
}
